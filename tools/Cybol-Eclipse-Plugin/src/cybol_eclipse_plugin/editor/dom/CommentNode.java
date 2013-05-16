package cybol_eclipse_plugin.editor.dom;

public final class CommentNode extends Node {
  
  
  public CommentNode(Node parent, String name /* = content */) {
    
    this.name = name;
    this.parent = parent;
    
    if (parent != null) {
      parent.children.add(this);
      
      this.level = parent.level + 1;
    }
  }
  
  
  @Override
  public int getNodeType() {
    return NT_COMMENT;
  }
}