package cybol_eclipse_plugin.editor;

import org.eclipse.jface.text.IDocument;
import org.eclipse.jface.text.contentassist.ContentAssistant;
import org.eclipse.jface.text.contentassist.IContentAssistant;
import org.eclipse.jface.text.reconciler.*;
import org.eclipse.jface.text.source.*;
import org.eclipse.ui.editors.text.TextSourceViewerConfiguration;


public final class CybolConfiguration extends TextSourceViewerConfiguration {
  
  
  private CybolEditor connectedEditor;
  private Reconciler reconciler;
  
  
  public CybolConfiguration(CybolEditor connectedEditor) {
    
    this.connectedEditor = connectedEditor;
    this.reconciler = new CybolReconciler();
  }
  
  
  @Override
  public IReconciler getReconciler(ISourceViewer sourceViewer) {
    return reconciler;
  }
  
  
  @Override
  public IContentAssistant getContentAssistant(ISourceViewer sourceViewer) {
    
    ContentAssistant assist = new ContentAssistant();
    assist.enableAutoActivation(true);
    assist.setContentAssistProcessor(new CybolContentAssistProcessor(), IDocument.DEFAULT_CONTENT_TYPE);
    assist.setInformationControlCreator(getInformationControlCreator(sourceViewer));
    assist.setDocumentPartitioning(IDocument.DEFAULT_CONTENT_TYPE);
    
    return assist;
  }
  
  
  public CybolEditor getEditor() {
    return connectedEditor;
  }
}