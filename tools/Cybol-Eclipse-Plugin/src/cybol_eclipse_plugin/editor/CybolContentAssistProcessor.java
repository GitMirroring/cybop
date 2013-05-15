package cybol_eclipse_plugin.editor;

import java.util.*;
import java.util.regex.*;

import org.eclipse.jface.text.ITextViewer;
import org.eclipse.jface.text.contentassist.CompletionProposal;
import org.eclipse.jface.text.contentassist.ICompletionProposal;
import org.eclipse.jface.text.contentassist.IContentAssistProcessor;
import org.eclipse.jface.text.contentassist.IContextInformation;
import org.eclipse.jface.text.contentassist.IContextInformationValidator;
import org.eclipse.swt.graphics.Image;

import cybol_eclipse_plugin.completion.*;


public final class CybolContentAssistProcessor implements IContentAssistProcessor {
  
  
  private static class TemplateReturnType {
    
    private String template;
    private int cursorOffset;
    
    public TemplateReturnType(String template, int cursorOffset) {
      this.template = template;
      this.cursorOffset = cursorOffset;
    }
    
    public String getTemplate() {
      return template;
    }
    
    public int getCursorOffset() {
      return cursorOffset;
    }
  }
  
  
  public CybolContentAssistProcessor() { }
  
  
  @Override
  public ICompletionProposal[] computeCompletionProposals(ITextViewer viewer, int offset) {
    
    String textBeforeCursor = viewer.getDocument().get().substring(0, offset);
    
    List<String> match;
    
    // check for tag
    match = checkRegex("(<[\\w\\d\\.:_]*)$", textBeforeCursor, 1);
    if (match != null) {
      
      return createTagProposals(match.get(0), offset);
    }
    
    // check for attribute name
    match = checkRegex("(?:<([\\w\\d\\._:]+)\\s+(?:[\\w\\d\\._:]+\\s*=\\s*(?:\"[^\"]*\"|'[^']')\\s+)*)([\\w\\d\\._:]*$)", textBeforeCursor, 1, 2);
    if (match != null) {
      
      return createAttributeProposals(match.get(0), match.get(1), offset);
    }
    
    // check for attribute value
    if ((match = checkRegex("\\s+([\\w\\d\\._:]+)\\s*=\\s*\"([^\"]*)$", textBeforeCursor, 1, 2)) != null ||
        (match = checkRegex("\\s+([\\w\\d\\._:]+)\\s*=\\s*'([^']*)$", textBeforeCursor, 1, 2)) != null) {
      
      return createValueProposals(match.get(0), match.get(1), offset);
    }
    
    return createAllProposals(offset);
  }
  
  

  @Override
  public IContextInformation[] computeContextInformation(ITextViewer viewer, int offset) {
    return null;
  }

  @Override
  public char[] getCompletionProposalAutoActivationCharacters() {
    return new char[] { '<', ' ', '"' };
  }

  @Override
  public char[] getContextInformationAutoActivationCharacters() {
    return null;
  }

  @Override
  public String getErrorMessage() {
    return "An error occured";
  }

  @Override
  public IContextInformationValidator getContextInformationValidator() {
    return null;
  }
  
  
  private static List<String> checkRegex(String regex, String input, int... returnIndices) {
    
    Pattern pattern = Pattern.compile(regex);
    
    Matcher matcher = pattern.matcher(input);
    
    if (matcher.find()) {
      
      List<String> returnValues = new ArrayList<String>();
      
      for (int index : returnIndices) {
        returnValues.add(matcher.group(index));
      }
      
      return returnValues;
    }
    
    return null;
  }
  
  
  private static ICompletionProposal[] createTagProposals(String tagName, int cursor) {
    
    final CompletionData TAGS = CompletionManager.getInstance().getCompletionData("tag", null);
    
    return createProposalsFromList(TAGS, tagName, cursor);
  }
  
  
  private static ICompletionProposal[] createAttributeProposals(String tagName, String attrName, int cursor) {
    
    final CompletionData ATTRIBUTES = CompletionManager.getInstance().getCompletionData("attribute", tagName);
    
    return createProposalsFromList(ATTRIBUTES, attrName, cursor);
  }
  
  
  private static ICompletionProposal[] createValueProposals(String attrName, String value, int cursor) {
    
    final CompletionData VALUES = CompletionManager.getInstance().getCompletionData("value", attrName);
    
    return createProposalsFromList(VALUES, value, cursor);
  }
  
  
  private static ICompletionProposal[] createAllProposals(int cursor) {
    
    final CompletionData ALL = CompletionManager.getInstance().getAllCompletionData();
    
    return createProposalsFromList(ALL, "", cursor);
  }
  
  
  private static ICompletionProposal[] createProposalsFromList(CompletionData completionData, String inputName, int cursor) {
    
    List<String> matches = getMatchingStrings(inputName, true, completionData.getNames());
    
    if (matches.size() == 0) {
      return null;
    }
    
    int length = inputName.length();
    
    ICompletionProposal[] proposals = new CompletionProposal[matches.size()];
    
    for (int i = 0; i < proposals.length; i++) {
      
      String match = matches.get(i);
      
      CompletionEntry entry = completionData.getCompletionEntry(match);
      
      String description = entry.getDescription();
      String template = entry.getTemplate();
      Image icon = entry.getIcon();
      
      TemplateReturnType templateInfo = analyzeTemplate(template, length);
      template = templateInfo.getTemplate();
      int cursorOffset = templateInfo.getCursorOffset();
      
      proposals[i] = new CompletionProposal(template, cursor - length, length, cursorOffset, icon, match, null, description);
    }
    
    return proposals;
  }
  
  
  private static List<String> getMatchingStrings(String input, boolean noEmptyList, String... stringList) {
    
    List<String> matches = new ArrayList<String>();
    
    input = input.toLowerCase();
    
    for (String entry : stringList) {
      
      if (entry.toLowerCase().contains(input)) {
        matches.add(entry);
      }
    }
    
    if (noEmptyList && matches.isEmpty()) {
      
      return Arrays.asList(stringList);
    }
    
    return matches;
  }
  
  
  private static TemplateReturnType analyzeTemplate(String template, int inputStringLength) {
    
    int cursorOffset = template.indexOf('|');
    
    if (cursorOffset == -1) {
      
      cursorOffset = template.length() - inputStringLength;
      
    } else {
      
      template = template.replace("|", "");
      
//      cursorOffset -= inputStringLength;
    }
    
    return new TemplateReturnType(template, cursorOffset);
  }
}