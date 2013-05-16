package cybol_eclipse_plugin.editor.dom;

import java.util.*;

public abstract class AttributedNode extends Node {
  
  protected List<AttributeNode> attributes = null;
  
  
  public List<AttributeNode> getAttributes() {
    return attributes;
  }
  
  public String getAttributeValue(String attributeName) {
    
    for (AttributeNode attribute : attributes) {
      
      if (attribute.getName().equals(attributeName)) {
        
        return attribute.getValue();
      }
    }
    
    return null;
  }
}