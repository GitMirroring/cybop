package cybol_eclipse_plugin.completion;

import java.io.*;

import javax.xml.parsers.*;
import javax.xml.xpath.*;

import org.eclipse.swt.graphics.Image;
import org.w3c.dom.*;
import org.xml.sax.SAXException;

import cybol_eclipse_plugin.*;


public final class CompletionManager {
  
  
  private static CompletionManager instance = null;
  
  
  private Document doc;
  private XPath xPath;
  
  
  public static CompletionManager getInstance() {
    
    if (instance == null) {
      
      instance = new CompletionManager("completion.xml");
    }
    
    return instance;
  }
  
  
  private CompletionManager(String uri) {
    
    try {
      DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
      DocumentBuilder builder = factory.newDocumentBuilder();
      
      InputStream stream = Activator.getDefault().getBundle().getEntry(uri).openStream();
      
      doc = builder.parse(stream);
      
      XPathFactory xPathFactory = XPathFactory.newInstance();
      xPath = xPathFactory.newXPath();
      
    } catch (ParserConfigurationException | SAXException | IOException ex) {
      ex.printStackTrace();
    }
    
    assert doc != null : "error while opening '" + uri + "'";
  }
  
  
  public CompletionData getCompletionData(String id, String parent) {
    
    if (parent == null) {
      parent = "";
    }
    
    try {
      XPathExpression expression = xPath.compile(String.format("Completion/Group[@id = '%s' and contains(@parent, '%s')]", id, parent, parent));
      Object result = expression.evaluate(doc, XPathConstants.NODE);
      
      if (result instanceof Node) {
        
        Node groupNode = (Node) result;
        
        String iconId = getAttributeValue(groupNode, "icon");
        Image icon = Util.getImage(iconId);
        
        CompletionData completionData = new CompletionData();
        
        for (int i = 0; i < groupNode.getChildNodes().getLength(); i++) {
          
          Node node = groupNode.getChildNodes().item(i);
          
          if ("Entry".equals(node.getNodeName())) {
          
            String name = getAttributeValue(node, "name");
            String description = getAttributeValue(node, "description");
            String template = getAttributeValue(node, "template");
            
            if (template == null) {
              template = name;
            }
            
            completionData.add(new CompletionEntry(name, description, template, icon));
          }
        }
        
        return completionData;
      }
      
    } catch (XPathExpressionException e) {
      e.printStackTrace();
    }
    
    return new CompletionData();
  }
  
  
  public CompletionData getAllCompletionData() {
    
    try {
      XPathExpression expression = xPath.compile("Completion/Group");
      Object result = expression.evaluate(doc, XPathConstants.NODESET);
      
      if (result instanceof NodeList) {
        
        NodeList groupNodes = (NodeList) result;
        
        CompletionData completionData = new CompletionData();
        
        for (int i = 0; i < groupNodes.getLength(); i++) {
          
          Node groupNode = groupNodes.item(i);
          
          String iconId = getAttributeValue(groupNode, "icon");
          Image icon = Util.getImage(iconId);
          
          for (int n = 0; n < groupNode.getChildNodes().getLength(); n++) {
            
            Node node = groupNode.getChildNodes().item(n);
            
            if ("Entry".equals(node.getNodeName())) {
            
              String name = getAttributeValue(node, "name");
              String description = getAttributeValue(node, "description");
              String template = getAttributeValue(node, "template");
              
              if (template == null) {
                template = name;
              }
              
              completionData.add(new CompletionEntry(name, description, template, icon));
            }
          }
        }
        
        return completionData;
      }
      
    } catch (XPathExpressionException e) {
      e.printStackTrace();
    }
    
    return new CompletionData();
  }
  
  
  private static String getAttributeValue(Node node, String attributeName) {
    
    if (node == null || attributeName == null) {
      return null;
    }
    
    Node attributeNode = node.getAttributes().getNamedItem(attributeName);
    
    if (attributeNode == null) {
      return null;
    }
    
    return attributeNode.getTextContent();
  }
}
