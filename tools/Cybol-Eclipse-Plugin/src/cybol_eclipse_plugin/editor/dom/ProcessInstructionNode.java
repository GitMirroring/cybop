package cybol_eclipse_plugin.editor.dom;

import java.util.*;

public final class ProcessInstructionNode extends AttributedNode {
  
  
  private boolean xmlDeclaration;
  
  public ProcessInstructionNode(Node parent, String name) {
    this(parent, name, false);
  }
  
  
  public ProcessInstructionNode(Node parent, String name, boolean xmlDeclaration) {
    
    attributes = new ArrayList<>();
    
    this.name = name;
    this.parent = parent;
    
    if (parent != null) {
      
      parent.children.add(this);
      
      level++;
    }
    
    this.xmlDeclaration = xmlDeclaration;
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
  
  
  public boolean isXmlDeclaration() {
    return xmlDeclaration;
  }
  
  
  @Override
  public int getNodeType() {
    return NT_PROCESS_INSTRUCTION;
  }
}