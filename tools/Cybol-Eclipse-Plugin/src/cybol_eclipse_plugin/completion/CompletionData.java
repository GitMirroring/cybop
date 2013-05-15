package cybol_eclipse_plugin.completion;

import java.util.*;


public final class CompletionData extends ArrayList<CompletionEntry> {
  
  private static final long serialVersionUID = -3191288032533047477L;
  
  
  public CompletionData() { }
  
  
  public String[] getNames() {
    
    String[] names = new String[this.size()];
    
    for (int i = 0; i < this.size(); i++) {
      names[i] = this.get(i).getName();
    }
    
    return names;
  }
  
  
  public CompletionEntry getCompletionEntry(String name) {
    
    for (CompletionEntry entry : this) {
      if (entry.getName().equals(name)) {
        return entry;
      }
    }
    
    return null;
  }
}