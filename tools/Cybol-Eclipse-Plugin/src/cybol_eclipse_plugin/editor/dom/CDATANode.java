package cybol_eclipse_plugin.editor.dom;

public class CDATANode extends Node {
  
  
  public CDATANode(Node parent, String name) {
    
    this.name = name;
    this.parent = parent;
    
    if (parent != null) {
      parent.children.add(this);
      
      this.level = parent.level + 1;
    }
  }
  
  
  @Override
  public int getNodeType() {
    return NT_CDATA;
  }
}