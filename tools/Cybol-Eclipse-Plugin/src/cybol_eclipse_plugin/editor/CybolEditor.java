package cybol_eclipse_plugin.editor;


import java.util.regex.*;

import org.eclipse.jface.text.IDocument;
import org.eclipse.jface.text.source.ISourceViewer;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.*;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.ui.texteditor.AbstractDecoratedTextEditor;


public final class CybolEditor extends AbstractDecoratedTextEditor {
  
  
  public CybolEditor() {
    setDocumentProvider(new CybolDocumentProvider());
    setSourceViewerConfiguration(new CybolConfiguration(this));
  }

  @Override
  public void createPartControl(Composite parent) {
    super.createPartControl(parent);
    
    
    this.getSourceViewer().getTextWidget().addKeyListener(new KeyAdapter() {
      
      @Override
      public void keyPressed(KeyEvent e) {
        if (e.keyCode == 94 && e.stateMask == SWT.CTRL) {
          jumpToNextAttribute();
        }
        if (e.keyCode == 94 && e.stateMask == (SWT.CTRL | SWT.SHIFT)) {
          jumpToPreviousAttribute();
        }
      }
    });
  }
  
  
  private void jumpToNextAttribute() {
    
    ISourceViewer sourceViewer = this.getSourceViewer();
    
    IDocument doc = sourceViewer.getDocument();
    int cursor = sourceViewer.getSelectedRange().x;
    
    String content = doc.get().substring(cursor);
    Range range = getFirstRangeFromRegEx("=\\s*(?:\"([^\"]*)\"|'([^']*)')", content, false);
    
    if (range != null) {
      sourceViewer.setSelectedRange(cursor + range.begin, range.length);
    }
  }
  
  
  private void jumpToPreviousAttribute() {
    
    ISourceViewer sourceViewer = this.getSourceViewer();
    
    IDocument doc = sourceViewer.getDocument();
    int cursor = sourceViewer.getSelectedRange().x;
    
    int searchBegin = doc.get().lastIndexOf('=', cursor);
    String content = doc.get().substring(0, searchBegin);
    
    Range range = getFirstRangeFromRegEx("=\\s*(?:\"([^\"]*)\"|'([^']*)')", content, true);
    
    if (range != null) {
      sourceViewer.setSelectedRange(range.begin, range.length);
    }
  }
  
  
  private static Range getFirstRangeFromRegEx(String regex, String input, boolean backwards) {
    
    Pattern pattern = Pattern.compile(regex);
    
    Matcher matcher = pattern.matcher(input);
    
    Range lastRange = null;
    
    while (matcher.find()) {
      
      int start = matcher.start(1);
      
      lastRange = new Range(start, matcher.end(1) - start);
      
      for (int i = 1; i < matcher.groupCount(); i++) {
        
        start = matcher.start(i + 1);
        
        if (start > -1 && (backwards && start > lastRange.begin || start < lastRange.begin)) {
          lastRange = new Range(start, matcher.end(i + 1) - start);
        }
      }
      
      if (!backwards) {
        break;
      }
    }
    
    return lastRange;
  }
}