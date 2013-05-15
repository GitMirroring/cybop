package cyboleclipseplugin.editor.dom;

public final class TextNode extends Node {
  
  
  public TextNode(TagNode parent, String name) {
    
    this.name = name;
    this.parent = parent;
    
    if (parent != null) {
      parent.children.add(this);
    }
  }
  
  
  @Override
  public String toString() {
    
    return name;
  }
  
  
  @Override
  public int getNodeType() {
    return NT_TEXT;
  }
}