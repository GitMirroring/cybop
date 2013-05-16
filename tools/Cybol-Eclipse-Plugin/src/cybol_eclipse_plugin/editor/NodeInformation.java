package cybol_eclipse_plugin.editor;

import java.util.ArrayList;
import java.util.List;

import cybol_eclipse_plugin.editor.dom.Node;


public final class NodeInformation {
  
  
  public static final int ATTRIBUTE_NAME = 1;
  public static final int ATTRIBUTE_VALUE = 2;
  public static final int EQUALS_SIGN = 3;
  public static final int CLOSING_TAG = 4;
  
  
  private int start;
  private int length;
  private Node relatedNode;
  
  private int additionalInfo;
  
  private List<String> errors;
  private List<String> warnings;
  
  
  public NodeInformation(Node relatedNode, int start, int length) {
    this(relatedNode, start, length, 0);
  }
  
  public NodeInformation(Node relatedNode, int start, int length, int additionalInfo) {
    this.relatedNode = relatedNode;
    this.start = start;
    this.length = length;
    this.additionalInfo = additionalInfo;
    
    errors = new ArrayList<>();
    warnings = new ArrayList<>();
  }
  
  
  public int getStart() {
    return start;
  }
  
  
  public int getLength() {
    return length;
  }
  
  
  public Node getRelatedNode() {
    return relatedNode;
  }
  
  
  public List<String> getErrors() {
    return errors;
  }
  
  
  public List<String> getWarnings() {
    return warnings;
  }
  
  
  public int getAdditionalInfo() {
    return additionalInfo;
  }
}