package cybol_eclipse_plugin.editor.dom;

import java.util.ArrayList;

public class UnknownNode extends Node {
  
  
  public UnknownNode(Node parent, String name) {
    
    this.name = name;
    this.parent = parent;
    
    this.children = new ArrayList<>();
    
    if (parent != null) {
      
      parent.children.add(this);
      
      this.level = parent.level + 1;
    }
  }
  
  
  @Override
  public int getNodeType() {
    return NT_UNKNOWN;
  }
}