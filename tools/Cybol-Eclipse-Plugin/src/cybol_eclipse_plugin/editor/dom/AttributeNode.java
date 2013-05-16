package cybol_eclipse_plugin.editor.dom;

import cybol_eclipse_plugin.editor.Range;

public class AttributeNode extends Node {
  
  private String value = null;
  
  private Range valueRange = null;
  private int assignmentPosition = -1;
  
  
  public AttributeNode(AttributedNode parent, String name) {
    
    this(parent, name, "");
  }
  
  
  public AttributeNode(AttributedNode parent, String name, String value) {
    
    this.name = name;
    this.parent = parent;
    this.value = value;
    
    if (parent != null) {
      
      parent.getAttributes().add(this);
//      System.out.println(parent.getAttributeValue("version"));
    }
  }
  
  
  public String getValue() {
    return value;
  }
  
  public void setValue(String value) {
    this.value = value;
  }
  
  
  @Override
  public String toString() {
    
    return "@" + name + "=\"" + value + "\"";
  }
  
  
  public Range getValueRange() {
    return valueRange;
  }
  
  public void setValueRange(Range valueRange) {
    this.valueRange = valueRange;
  }
  
  
  public int getAssignmentPosition() {
    return assignmentPosition;
  }
  
  public void setAssignmentPosition(int assignmentPosition) {
    this.assignmentPosition = assignmentPosition;
  }
  
  
  @Override
  public int getNodeType() {
    return NT_ATTRIBUTE;
  }
}