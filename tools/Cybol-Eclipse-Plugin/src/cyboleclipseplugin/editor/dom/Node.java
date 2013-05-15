package cyboleclipseplugin.editor.dom;

import java.util.List;

import cybol_eclipse_plugin.editor.Range;

public abstract class Node {
  
  public static final int NT_ATTRIBUTE           = 0;
  public static final int NT_CDATA               = 1;
  public static final int NT_COMMENT             = 2;
  public static final int NT_DOCUMENT            = 3;
  public static final int NT_PROCESS_INSTRUCTION = 4;
  public static final int NT_TAG                 = 5;
  public static final int NT_TEXT                = 6;
  public static final int NT_UNKNOWN             = 7;
  public static final int NT_VALUE               = 8;
  public static final int NT_EQUALS_SIGN            = 9;
  
  public static final int MISSING_NAME                  = 0x1;
  public static final int MISSING_CLOSE_TAG             = 0x2;
  public static final int MISSING_VALUE                 = 0x4;
  public static final int BROKEN_NAME                   = 0x8;
  public static final int INAPPROPRIATE_END             = 0x10;
  public static final int BROKEN_VALUE                  = 0x20;
  public static final int MISSING_START_QUOTE           = 0x40;
  public static final int MISSING_END_QUOTE             = 0x80;
  public static final int BROKEN_CLOSE                  = 0x100;
  public static final int MISSING_CLOSE                 = 0x200;
  public static final int WRONG_CLOSE_TAG               = 0x400;
  public static final int MISSING_DECLARATION           = 0x800;
  public static final int MISSING_VERSION_ATTRIBUTE     = 0x1000;
  public static final int FORBIDDEN_ATTRIBUTE           = 0x2000;
  public static final int BROKEN_PROCESSING_INSTRUCTION = 0x4000;
  public static final int BROKEN_DECLARATION_POSITION   = 0x8000;
  
  
  protected String name = null;
  protected int level = -1;
  
  protected Range range = null;
  
  protected List<Node> children = null;
  
  
  protected Node parent = null;
  
  protected int flags = 0;
  
  
  public String getName() {
    return name;
  }
  
  public void setName(String name) {
    this.name = name;
  }
  
  
  public Node getParent() {
    return parent;
  }
  
  
  public boolean hasChildren() {
    return children != null && children.size() > 0;
  }
  
  public List<Node> getChildren() {
    return children;
  }
  
  public Range getRange() {
    return range;
  }
  
  public void setRange(Range range) {
    this.range = range;
  }
  
  
  public int getLevel() {
    return level;
  }
  
  public void setLevel(int level) {
    this.level = level;
  }
  
  
  public void putFlag(int flag) {
    flags |= flag;
  }
  
  public boolean isFlag(int flag) {
    return (flags & flag) == flag;
  }
  
  
  public String __debug__extractFlags() {
    
    java.util.List<String> flags = new java.util.ArrayList<String>();
    
    if (isFlag(BROKEN_NAME)) {
      flags.add("BROKEN_NAME");
    }
    if (isFlag(INAPPROPRIATE_END)) {
      flags.add("INAPPROPRIATE_END");
    }
    if (isFlag(MISSING_CLOSE_TAG)) {
      flags.add("MISSING_CLOSE_TAG");
    }
    if (isFlag(MISSING_NAME)) {
      flags.add("MISSING_NAME");
    }
    if (isFlag(MISSING_VALUE)) {
      flags.add("MISSING_VALUE");
    }
    if (isFlag(MISSING_START_QUOTE)) {
      flags.add("MISSING_START_QUOTE");
    }
    if (isFlag(MISSING_END_QUOTE)) {
      flags.add("MISSING_END_QUOTE");
    }
    if (isFlag(BROKEN_CLOSE)) {
      flags.add("BROKEN_CLOSE");
    }
    if (isFlag(MISSING_CLOSE)) {
      flags.add("MISSING_CLOSE");
    }
    if (isFlag(WRONG_CLOSE_TAG)) {
      flags.add("WRONG_CLOSE_TAG");
    }
    if (isFlag(MISSING_DECLARATION)) {
      flags.add("MISSING_DECLARATION");
    }
    if (isFlag(MISSING_VERSION_ATTRIBUTE)) {
      flags.add("MISSING_VERSION_ATTRIBUTE");
    }
    if (isFlag(FORBIDDEN_ATTRIBUTE)) {
      flags.add("FORBIDDEN_ATTRIBUTE");
    }
    if (isFlag(BROKEN_PROCESSING_INSTRUCTION)) {
      flags.add("BROKEN_PROCESSING_INSTRUCTION");
    }
    if (isFlag(BROKEN_DECLARATION_POSITION)) {
      flags.add("BROKEN_DECLARATION_POSITION");
    }
    
    if (flags.size() == 0) {
      return null;
    } else {
      return flags.toString();
    }
  }
  
  
  public Node getNextSibling() {
    
    if (parent == null) {
      return null;
    }
    
    int index = parent.getChildren().indexOf(this) + 1;
    
    if (index == parent.getChildren().size()) {
      return null;
    }
    
    return parent.getChildren().get(index);
  }
  
  
  public Node getNextNode() {
    
    if (hasChildren()) {
      
      return this.getChildren().get(0);
    } else {
      
      Node sibling = getNextSibling();
      
      if (sibling != null) {
        return sibling;
      }
      
      Node node = this;
      
      while (node.getNodeType() != Node.NT_DOCUMENT) {
        
//        Node __debug__lastNode = node;
        node = node.getParent();
        sibling = node.getNextSibling();
        
        if (sibling != null) {
          return sibling;
        }
      }
    }
    
    return null;
  }
  
  
  public abstract int getNodeType();
}