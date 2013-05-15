package cybol_eclipse_plugin.editor;

import org.eclipse.core.runtime.CoreException;
import org.eclipse.jface.text.IDocument;
import org.eclipse.ui.editors.text.FileDocumentProvider;


public final class CybolDocumentProvider extends FileDocumentProvider {
  
  
  @Override
  protected IDocument createDocument(Object element) throws CoreException {
    
    IDocument document = super.createDocument(element);
    
    XMLPartitioner partitioner = new XMLPartitioner();
    partitioner.connect(document);
    document.setDocumentPartitioner(partitioner);
    
    return document;
  }
  
  
  
}