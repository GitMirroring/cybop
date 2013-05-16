package cybol_eclipse_plugin.editor;

import org.eclipse.jface.text.DocumentEvent;
import org.eclipse.jface.text.IDocument;
import org.eclipse.jface.text.IDocumentPartitioner;
import org.eclipse.jface.text.ITypedRegion;
import org.eclipse.jface.text.TypedRegion;

import cybol_eclipse_plugin.editor.dom.DocumentNode;


public final class XMLPartitioner implements IDocumentPartitioner {
  
  
  private XMLDocumentParser parser;
  private DocumentNode root = null;
  private IDocument currentDocument = null;
  
  
  public XMLPartitioner() {
    parser = new XMLDocumentParser();
  }
  
  
  @Override
  public void connect(IDocument document) {
    System.out.println("connect: " + document + " (" + document.getLength() + ")");
    
    currentDocument = document;
//    parseDocument();
  }

  @Override
  public void disconnect() {
    
  }

  @Override
  public void documentAboutToBeChanged(DocumentEvent event) {
  }

  @Override
  public boolean documentChanged(DocumentEvent event) {
    currentDocument = event.getDocument();
    return false;
  }

  @Override
  public String[] getLegalContentTypes() {
    return new String[] { IDocument.DEFAULT_CONTENT_TYPE };
  }

  @Override
  public String getContentType(int offset) {
    return IDocument.DEFAULT_CONTENT_TYPE;
  }

  @Override
  public ITypedRegion[] computePartitioning(int offset, int length) {
    
    return new ITypedRegion[] { new TypedRegion(0 ,currentDocument.getLength(), IDocument.DEFAULT_CONTENT_TYPE) };
  }

  @Override
  public ITypedRegion getPartition(int offset) {
    
    return new TypedRegion(0, currentDocument.getLength(), IDocument.DEFAULT_CONTENT_TYPE);
  }
  
  
  public void parseDocument() {
    
    try {
      parser.setDocument(currentDocument);
      root = parser.parse();
    } catch (InvalidXMLDocumentException ex) {
      ex.printStackTrace();
    }
  }
  
  
  public DocumentNode getRootNode() {
    return root;
  }
}