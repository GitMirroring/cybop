package cybol_eclipse_plugin.editor.dom;

import java.util.*;

import cybol_eclipse_plugin.editor.Range;

public final class TagNode extends AttributedNode {
  
  
  private Range secondTagRange = null;
  
  private boolean xslTag = false;
  
  
  public TagNode(Node parent, String name) {
    
    this(parent, name, false);
  }
  
  
  public TagNode(Node parent, String name, boolean isXslTag) {
    
    this.name = name;
    this.parent = parent;
    this.xslTag = isXslTag;
    
    this.children = new ArrayList<>();
    attributes = new ArrayList<>();
    
    if (parent != null) {
      
      parent.children.add(this);
      
      this.level++;
    }
  }
  
  
  @Override
  public List<AttributeNode> getAttributes() {
    return attributes;
  }
  
  
  @Override
  public String getAttributeValue(String attributeName) {
    
    for (AttributeNode attribute : attributes) {
      
      if (attribute.getName().equals(attributeName)) {
        
        return attribute.getValue();
      }
    }
    
    return null;
  }
  
  
  public Range getSecondTagRange() {
    return secondTagRange;
  }
  
  public void setSecondTagRange(Range secondTag) {
    this.secondTagRange = secondTag;
  }
  
  
  public boolean isXslTag() {
    return xslTag;
  }
  
  public void setXslTag(boolean xslTag) {
    this.xslTag = xslTag;
  }
  
  
  @Override
  public String toString() {
    
    String attrs = "";
    
    for (AttributeNode attr : attributes) {
      attrs += attr.name + "=\"" + attr.getValue() + "\" ";
    }
    
    return "<" + name + " " + attrs + (children.size() == 0 ? "" : "/") + ">";
  }
  
  
  @Override
  public int getNodeType() {
    return NT_TAG;
  }
}