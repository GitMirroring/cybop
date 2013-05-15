package cybol_eclipse_plugin.editor;

public final class Range {
  
  
  public int begin = -1;
  public int length = -1;
  
  public Range(int begin) {
    
    this(begin, 0);
  }
  
  
  public Range(int begin, int length) {
    
    this.begin = begin;
    this.length = length;
  }
  
  
  public void set(int begin, int length) {
    this.begin = begin;
    this.length = length;
  }
  
  
  public void setEnd(int end) {
    this.length = end - begin;
  }
  
  
  @Override
  public Range clone() {
    return new Range(begin, length);
  }
}