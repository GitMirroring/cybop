package cybol_eclipse_plugin.editor;


import java.util.*;

import org.eclipse.jface.text.*;
import org.eclipse.jface.text.reconciler.DirtyRegion;
import org.eclipse.jface.text.reconciler.Reconciler;
import org.eclipse.jface.text.source.*;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.StyleRange;
import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.widgets.Display;

import cybol_eclipse_plugin.editor.Range;
import cyboleclipseplugin.editor.dom.*;


public class CybolReconciler extends Reconciler {
  
  
  private final static Color COLOR_BLACK = new Color(Display.getCurrent(), 0, 0, 0);
  private final static Color COLOR_RED = new Color(Display.getCurrent(), 255, 0, 0);
  
//  private final static Color COLOR_DARK_BLUE = new Color(Display.getCurrent(), 0, 0, 155);
  private final static Color COLOR_DARK_GREEN = new Color(Display.getCurrent(), 0, 155, 0);
  private final static Color COLOR_DARK_RED = new Color(Display.getCurrent(), 155, 0, 0);
  private final static Color COLOR_LIGHT_BLUE = new Color(Display.getCurrent(), 0, 190, 210);
  private final static Color COLOR_GRAY = new Color(Display.getCurrent(), 128, 128, 128);
  private final static Color COLOR_PURPLE = new Color(Display.getCurrent(), 160, 0, 30);
  private final static Color COLOR_GOLD = new Color(Display.getCurrent(), 210, 180, 60);
  
  
  public CybolReconciler() { }
  
  
  @Override
  protected void reconcilerDocumentChanged(IDocument document) {
    super.reconcilerDocumentChanged(document);
    
    updateModelAndPresentation();
  }
  
  
  @Override
  protected void process(DirtyRegion dirtyRegion) {
    super.process(dirtyRegion);
    
    updateModelAndPresentation();
  }
  
  
  public void colorizeSheet(DocumentNode root) {
    
    final ITextViewer fViewer = this.getTextViewer();
    
    if (root != null) {
      
      final TextPresentation textAttributes = new TextPresentation();
      
      colorizeElements(root, textAttributes);
      
      fViewer.getTextWidget().getDisplay().asyncExec(new Runnable() {
        
        @Override
        public void run() {
          
          fViewer.changeTextPresentation(textAttributes, false);
        }
      });
    }
  }
  
  
  private void colorizeElements(Node node, TextPresentation textAttributes) {
    
//    StyleRange styleRange;
    
    // durch die einzelnen Nodes iterieren und dem entsprechend den Text einfärben
    
    // - debug - //
    String flags = node.__debug__extractFlags();
    if (flags != null) {
      System.out.println(node.getName() + ": " + flags);
    }
    
    AttributedNode attributedNode = node instanceof AttributedNode ? (AttributedNode) node : null;
    Range range = node.getRange();
    
    // prüfen, ob ein Node Attribute besitzt
    
    if (attributedNode != null && attributedNode.getAttributes().size() > 0) {
      
      if (range != null) {
        
        if (flags != null) {
          
//          styleRange = new StyleRange(range.begin, attributedNode.getAttributes().get(0).getRange().begin - range.begin, getColorFromNode(node), COLOR_RED, SWT.BOLD);
          textAttributes.addStyleRange(getStyleFromNodeTypeError(range.begin, attributedNode.getAttributes().get(0).getRange().begin - range.begin, node.getNodeType()));
          
        } else {
          
//          styleRange = new StyleRange(range.begin, attributedNode.getAttributes().get(0).getRange().begin - range.begin, getColorFromNode(node), null, SWT.BOLD);
          textAttributes.addStyleRange(getStyleFromNodeType(range.begin, attributedNode.getAttributes().get(0).getRange().begin - range.begin, node.getNodeType()));
        }
      }
      
      // durch dir Attribute iterieren
      
      for (AttributeNode attribute : attributedNode.getAttributes()) {
        
        // - debug - //
        flags = attribute.__debug__extractFlags();
        if (flags != null) {
          System.out.println(attribute.getName() + ": " + flags);
        }
        
//        if (attribute.isFlag(Node.INAPPROPRIATE_END)) {
//          
//        } else {
        
        
        if (attribute.isFlag(Node.BROKEN_NAME)) {
          
//          styleRange = new StyleRange(attribute.getRange().begin, attribute.getRange().length, COLOR_BLACK, COLOR_RED, SWT.BOLD);
          textAttributes.addStyleRange(getStyleFromNodeTypeError(attribute.getRange().begin, attribute.getRange().length, Node.NT_ATTRIBUTE));
          
        } else {
          
//          styleRange = new StyleRange(attribute.getRange().begin, attribute.getRange().length, COLOR_BLACK, null, SWT.BOLD);
          textAttributes.addStyleRange(getStyleFromNodeType(attribute.getRange().begin, attribute.getRange().length, Node.NT_ATTRIBUTE));
        }
        
        
        if (attribute.getAssignmentPosition() != -1) {
//          styleRange = new StyleRange(attribute.getAssignmentPosition(), 1, COLOR_BLACK, null, SWT.BOLD);
          textAttributes.addStyleRange(getStyleFromNodeType(attribute.getAssignmentPosition(), 1, Node.NT_EQUALS_SIGN));
        }
        
        // - debug - //
        if (attribute.getValueRange() == null) {
          System.out.println("ERROR: ValueRange fehlt: - " + attribute);
        } else {
          
          if (attribute.isFlag(Node.BROKEN_VALUE)) {
            
//            styleRange = new StyleRange(attribute.getValueRange().begin, attribute.getValueRange().length, COLOR_BLUE, COLOR_RED, SWT.ITALIC);
            textAttributes.addStyleRange(getStyleFromNodeTypeError(attribute.getValueRange().begin, attribute.getValueRange().length, Node.NT_VALUE));
            
          } else {
            
//            styleRange = new StyleRange(attribute.getValueRange().begin - 1, attribute.getValueRange().length + 2, COLOR_BLUE, null, SWT.ITALIC);
            textAttributes.addStyleRange(getStyleFromNodeType(attribute.getValueRange().begin - 1, attribute.getValueRange().length + 2, Node.NT_VALUE));
          }
        }
      }
      
    } else if (node instanceof UnknownNode) {
      
//      styleRange = new StyleRange(range.begin, range.length, COLOR_BLACK, COLOR_RED);
      textAttributes.addStyleRange(getStyleFromNodeTypeError(range.begin, range.length, node.getNodeType()));
      
    } else if (range != null) {
      
      if (flags != null) {
        
//        styleRange = new StyleRange(range.begin, range.length, getColorFromNode(node), COLOR_RED, SWT.BOLD);
        textAttributes.addStyleRange(getStyleFromNodeTypeError(range.begin, range.length, node.getNodeType()));
        
      } else {
        
//        styleRange = new StyleRange(range.begin, range.length, getColorFromNode(node), null, SWT.BOLD);
        textAttributes.addStyleRange(getStyleFromNodeType(range.begin, range.length, node.getNodeType()));
      }
    }
    
    
    // rekursiv Kinder aufrufen und einfärben
    
    if (node.hasChildren()) {
      
      for (Node child : node.getChildren()) {
        
        colorizeElements(child, textAttributes);
      }
    }
    
    // überprüfen, ob ein schließendes Tag existiert und dieses auch einfärben
    
    if (node instanceof TagNode) {
      range = ((TagNode) node).getSecondTagRange();
      
      if (range != null) {
        
        if (node.isFlag(Node.WRONG_CLOSE_TAG)) {
          
//          styleRange = new StyleRange(range.begin, range.length, getColorFromNode(node), COLOR_RED, SWT.BOLD);
          textAttributes.addStyleRange(getStyleFromNodeTypeError(range.begin, range.length, Node.NT_TAG));
        } else {
          
//        styleRange = new StyleRange(range.begin, range.length, getColorFromNode(node), null, SWT.BOLD);
          textAttributes.addStyleRange(getStyleFromNodeType(range.begin, range.length, Node.NT_TAG));
        }
      }
    }
  }
  
  
  private static StyleRange getStyleFromNodeType(int start, int length, int type) {
    
    switch (type) {
      case Node.NT_TAG:
        return new StyleRange(start, length, COLOR_DARK_GREEN, null, SWT.BOLD);
      case Node.NT_ATTRIBUTE:
        return new StyleRange(start, length, COLOR_DARK_RED, null);
      case Node.NT_EQUALS_SIGN:
        return new StyleRange(start, length, COLOR_DARK_RED, null);
      case Node.NT_VALUE:
        return new StyleRange(start, length, COLOR_LIGHT_BLUE, null, SWT.ITALIC);
      case Node.NT_PROCESS_INSTRUCTION:
      case Node.NT_DOCUMENT:
        return new StyleRange(start, length, COLOR_PURPLE, null);
      case Node.NT_TEXT:
        return new StyleRange(start, length, COLOR_BLACK, null);
      case Node.NT_COMMENT:
        return new StyleRange(start, length, COLOR_GRAY, null);
      case Node.NT_CDATA:
        return new StyleRange(start, length, COLOR_GOLD, null);
      default:
        return new StyleRange(start, length, COLOR_BLACK, null);
    }
  }
  
  
  // TODO - wird später durch Annotations ersetzt
  private static StyleRange getStyleFromNodeTypeError(int start, int length, int type) {
    
    switch (type) {
      case Node.NT_TAG:
        return new StyleRange(start, length, COLOR_DARK_GREEN, COLOR_RED, SWT.BOLD);
      case Node.NT_ATTRIBUTE:
        return new StyleRange(start, length, COLOR_DARK_RED, COLOR_RED);
      case Node.NT_EQUALS_SIGN:
        return new StyleRange(start, length, COLOR_DARK_RED, COLOR_RED);
      case Node.NT_VALUE:
        return new StyleRange(start, length, COLOR_LIGHT_BLUE, COLOR_RED, SWT.ITALIC);
      case Node.NT_PROCESS_INSTRUCTION:
      case Node.NT_DOCUMENT:
        return new StyleRange(start, length, COLOR_PURPLE, COLOR_RED);
      case Node.NT_TEXT:
        return new StyleRange(start, length, COLOR_BLACK, COLOR_RED);
      case Node.NT_COMMENT:
        return new StyleRange(start, length, COLOR_GRAY, COLOR_RED);
      case Node.NT_CDATA:
        return new StyleRange(start, length, COLOR_GOLD, COLOR_RED);
      default:
        return new StyleRange(start, length, COLOR_BLACK, COLOR_RED);
    }
  }
  
  
  private void updateModelAndPresentation() {
    
    if (this.getDocument().getDocumentPartitioner() instanceof XMLPartitioner) {
      
      XMLPartitioner partitioner = (XMLPartitioner) this.getDocument().getDocumentPartitioner();
      partitioner.parseDocument();
//      colorizeSheet(partitioner.getRootNode());
      
      CybolAnalyzer cybolAnalyzer = new CybolAnalyzer();
      final List<NodeInformation> nodes = cybolAnalyzer.analyze(partitioner.getRootNode());
      
      if (nodes.size() > 0) {
        final TextPresentation textAttributes = new TextPresentation(nodes.size());
        
        for (NodeInformation info : nodes) {
          
          int type = info.getRelatedNode().getNodeType();
          
          if (info.getRelatedNode() instanceof AttributeNode) {
            if (info.getAdditionalInfo() == NodeInformation.ATTRIBUTE_VALUE) {
              type = Node.NT_VALUE;
            } else if (info.getAdditionalInfo() == NodeInformation.EQUALS_SIGN) {
              type = Node.NT_EQUALS_SIGN;
            }
          }
          
          textAttributes.addStyleRange(getStyleFromNodeType(info.getStart(), info.getLength(), type));
        }
        
        final ITextViewer fViewer = this.getTextViewer();
        
        fViewer.getTextWidget().getDisplay().asyncExec(new Runnable() {
          
          @Override
          public void run() {
            
            updateAnnotations(nodes);
          }
        });
        
        fViewer.getTextWidget().getDisplay().asyncExec(new Runnable() {
          
          @Override
          public void run() {
            
            fViewer.changeTextPresentation(textAttributes, false);
          }
        });
        
      }
    } else {
      
      throw new RuntimeException("The document partitioner of a cybol editor must be an XMLPartitioner!");
    }
  }
  
  
  private void updateAnnotations(List<NodeInformation> nodes) {
    
    if (this.getTextViewer() instanceof ISourceViewer) {
      
      ISourceViewer sourceViewer = (ISourceViewer) this.getTextViewer();
      IAnnotationModel annotationModel = sourceViewer.getAnnotationModel();
      
      if (annotationModel instanceof IAnnotationModelExtension) {
        
        IAnnotationModelExtension annotationModelExtension = (IAnnotationModelExtension) annotationModel;
        List<Annotation> oldAnnotationList = new ArrayList<>();
        Map<Annotation, Position> newAnnotations = new HashMap<Annotation, Position>();
        
        for (@SuppressWarnings("unchecked")
        Iterator<Annotation> iterator = annotationModel.getAnnotationIterator(); iterator.hasNext();) {
          
          Annotation annotation = iterator.next();
          
          if (annotation.getType().equals("MyMarkerAnnotation")) {
            oldAnnotationList.add(annotation);
          }
        }
        
        for (NodeInformation info : nodes) {
          
          if (!info.getErrors().isEmpty()) {
            
            Position position = new Position(info.getStart(), info.getLength());
            
            for (String message : info.getErrors()) {
              
              Annotation annotation = new Annotation("MyMarkerAnnotation", false, message);
              newAnnotations.put(annotation, position);
            }
          }
        }
        
        Annotation[] oldAnnotations = oldAnnotationList.toArray(new Annotation[oldAnnotationList.size()]);
        
        annotationModelExtension.replaceAnnotations(oldAnnotations, newAnnotations);
      }
    }
  }
}