package cybol_eclipse_plugin.editor.dom;

import java.util.*;

import cybol_eclipse_plugin.editor.Range;

public final class DocumentNode extends AttributedNode {
  
  
  private ProcessInstructionNode declaration;
  
  public DocumentNode() {
    
    attributes = new ArrayList<>();
    
    this.name = "XML";
    
    this.children = new ArrayList<>();
    
    this.level = 0;
    
    // little hack
    this.parent = this;
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
  
  
  @Override
  public String toString() {
    
    String attrs = "";
    
    for (AttributeNode attr : attributes) {
      attrs += attr.name + "=\"" + attr.getValue() + "\" ";
    }
    
    return "<" + name + " " + attrs + (children.size() == 0 ? "" : "/") + ">";
  }
  
  
  public ProcessInstructionNode getDeclarationNode() {
    return declaration;
  }
  
  public void setDeclarationNode(ProcessInstructionNode declaration) {
    this.declaration = declaration;
  }
  
  
  @Override
  public int getNodeType() {
    return NT_DOCUMENT;
  }
  
  
  public Node getNodeFromOffset(int offset) {
    
    Range range;
    Node currentNode = this;
    
    while (currentNode != null) {
      
      range = currentNode.getRange();
      
      if (range != null) {
        if (offset >= range.begin && offset < range.begin + range.length) {
          
          if (currentNode instanceof AttributedNode) {
            
            for (AttributeNode attrNode : ((AttributedNode) currentNode).getAttributes()) {
              
              range = attrNode.getRange();
              if (offset >= range.begin && offset < range.begin + range.length) {
                return attrNode;
              }
              
              range = attrNode.getValueRange();
              if (offset >= range.begin && offset < range.begin + range.length) {
                return attrNode;
              }
            }
          }
          
          return currentNode;
          
        } else if (currentNode instanceof TagNode) {
          
          if ((range = ((TagNode) currentNode).getSecondTagRange()) != null) {
            
            if (offset >= range.begin && offset < range.begin + range.length) {
              return currentNode;
            }
          }
        }
      }
      
      currentNode = currentNode.getNextNode();
    }
    
    return null;
  }
}