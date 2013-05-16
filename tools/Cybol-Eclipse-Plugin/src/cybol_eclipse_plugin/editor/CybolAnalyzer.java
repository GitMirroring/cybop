package cybol_eclipse_plugin.editor;

import java.util.ArrayList;
import java.util.List;

import cybol_eclipse_plugin.editor.dom.*;


public final class CybolAnalyzer {
  
  
  private List<NodeInformation> nodes;
  
  
  public CybolAnalyzer() { }
  
  
  public List<NodeInformation> analyze(DocumentNode root) {
    
    nodes = new ArrayList<>();
    
    if (root != null) {
      
      analyzeNode(root);
    }
    
    return nodes;
  }
  
  
  private void analyzeNode(Node node) {
    
    NodeInformation info;
    AttributedNode attributedNode = node instanceof AttributedNode ? (AttributedNode) node : null;
    Range range = node.getRange();
    
    List<String> messages = new ArrayList<>();
    
    if (node instanceof TagNode) {
      
      messages = getCybolTagErrorMessages((TagNode) node);
    }
    
    // prüfen, ob ein Node Attribute besitzt
    
    if (attributedNode != null && attributedNode.getAttributes().size() > 0) {
      
      info = new NodeInformation(node, range.begin, 
          attributedNode.getAttributes().get(0).getRange().begin - range.begin, 
          NodeInformation.ATTRIBUTE_NAME);
      info.getErrors().addAll(getErrorMessagesFromFlag(node));
      info.getErrors().addAll(messages);
      
      nodes.add(info);
      
      // durch dir Attribute iterieren
      
      for (AttributeNode attribute : attributedNode.getAttributes()) {
        
        messages = getCybolAttributeErrorMessages(attribute);
        
        info = new NodeInformation(attribute, attribute.getRange().begin, attribute.getRange().length);
        info.getErrors().addAll(getErrorMessagesFromFlag(node));
        info.getErrors().addAll(messages);
        nodes.add(info);
        
        if (attribute.getAssignmentPosition() != -1) {
          nodes.add(new NodeInformation(attribute, attribute.getAssignmentPosition(), 1, 
              NodeInformation.EQUALS_SIGN));
        }
        
        // - debug - //
        if (attribute.getValueRange() == null) {
          System.out.println("ERROR: ValueRange fehlt: - " + attribute);
        } else {
          nodes.add(new NodeInformation(attribute, attribute.getValueRange().begin, 
              attribute.getValueRange().length, NodeInformation.ATTRIBUTE_VALUE));
        }
      }
      
    } else if (range != null) {
      
      info = new NodeInformation(node, range.begin, range.length);
      info.getErrors().addAll(getErrorMessagesFromFlag(node));
      nodes.add(info);
    }
    
    
    // rekursiv Kinder aufrufen und einfärben
    
    if (node.hasChildren()) {
      
      for (Node child : node.getChildren()) {
        
        analyzeNode(child);
      }
    }
    
    // überprüfen, ob ein schließendes Tag existiert und dieses auch einfärben
    
    if (node instanceof TagNode) {
      range = ((TagNode) node).getSecondTagRange();
      
      if (range != null) {
        
        nodes.add(new NodeInformation(node, range.begin, range.length, NodeInformation.CLOSING_TAG));
      }
    }
  }
  
  
  private static List<String> getCybolTagErrorMessages(TagNode node) {
    
    List<String> messages = new ArrayList<>();
    
    if (node.getName().equals("model")) {
      if (node.getLevel() != 1) {
        messages.add("»model« is only possible as top level tag");
      }
//      if (node != null && node.getAttributes().size() > 0) {
//        messages.add("»model« must not have any attributes");
//      }
      
    } else if (node.getName().equals("part")) {
      if (node.getParent() == null || !node.getParent().getName().equals("model")) {
        messages.add("»part« must only be a child of »model«");
      }
      if (node.getAttributes().contains("name")) {
        messages.add("»part« must have a »name« attribute");
      }
      if (node.getAttributes().contains("channel")) {
        messages.add("»part« must have a »channel« attribute");
      }
      if (node.getAttributes().contains("format")) {
        messages.add("»part« must have a »format« attribute");
      }
      if (node.getAttributes().contains("encoding")) {
        messages.add("»part« must have an »encoding« attribute");
      }
      if (node.getAttributes().contains("model")) {
        messages.add("»part« must have a »model« attribute");
      }
      
    } else if (node.getName().equals("property")) {
      if (node.getParent() == null || !node.getParent().getName().equals("part")) {
        messages.add("»property« must only be a child of »part«");
      }
      if (node.getAttributes().contains("name")) {
        messages.add("»property« must have a »name« attribute");
      }
      if (node.getAttributes().contains("channel")) {
        messages.add("»property« must have a »channel« attribute");
      }
      if (node.getAttributes().contains("format")) {
        messages.add("»property« must have a »format« attribute");
      }
      if (node.getAttributes().contains("encoding")) {
        messages.add("»property« must have an »encoding« attribute");
      }
      if (node.getAttributes().contains("model")) {
        messages.add("»property« must have a »model« attribute");
      }
    }
    
    return messages;
  }
  
  
  private static List<String> getCybolAttributeErrorMessages(AttributeNode node) {
    
    List<String> messages = new ArrayList<>();
    
    if (node.getParent().getName().equals("model")) {
      messages.add(String.format("»%s« is no valid attribute for »model«", node.getName()));
      
    } else if (node.getParent().getName().equals("part")) {
      if (node.getName().equals("name") || node.getName().equals("channel") || 
          node.getName().equals("format") || node.getName().equals("encoding") || 
          node.getName().equals("model")) {
        
        // TODO - check conent
        
      } else {
        messages.add(String.format("»%s« is no valid attribute for »part«", node.getName()));
      }
    } else if (node.getParent().getName().equals("property")) {
      if (node.getName().equals("name") || node.getName().equals("channel") || 
          node.getName().equals("format") || node.getName().equals("encoding") || 
          node.getName().equals("model")) {
        
        // TODO - check conent
        
      } else {
        messages.add(String.format("»%s« is no valid attribute for »property«", node.getName()));
      }
    }
    
    return messages;
  }
  
  
  private static List<String> getErrorMessagesFromFlag(Node node) {
    
    List<String> messages = new ArrayList<>();
    
    if (node.isFlag(Node.MISSING_NAME)) {
      messages.add("The name is missing");
    }
    if (node.isFlag(Node.MISSING_CLOSE_TAG)) {
      messages.add("The closing tag is missing");
    }
    if (node.isFlag(Node.MISSING_VALUE)) {
      messages.add("The value is missing");
    }
    if (node.isFlag(Node.BROKEN_NAME)) {
      messages.add("The name is not valid");
    }
    if (node.isFlag(Node.MISSING_VALUE)) {
      messages.add("The value is missing");
    }
    if (node.isFlag(Node.INAPPROPRIATE_END)) {
      messages.add("Inappropriate end");
    }
    if (node.isFlag(Node.BROKEN_VALUE)) {
      messages.add("The value is invalid");
    }
    if (node.isFlag(Node.MISSING_START_QUOTE)) {
      messages.add("The value needs to be between quotes");
    }
    if (node.isFlag(Node.MISSING_END_QUOTE)) {
      messages.add("The value needs to be between quotes");
    }
    if (node.isFlag(Node.BROKEN_CLOSE)) {
      messages.add("TODO - could be removed later");
    }
    if (node.isFlag(Node.MISSING_CLOSE)) {
      messages.add("The closing tag is missing");
    }
    if (node.isFlag(Node.WRONG_CLOSE_TAG)) {
      messages.add("the closing tag does not fit the opening tag");
    }
    
    return messages;
  }
}