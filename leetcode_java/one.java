package leetcode_java;

import java.util.HashSet;
import java.util.Set;

class Solution202_1 {
  public boolean isHappy(int n) {
    boolean result = true;
    Set<Integer> set = new HashSet<>();
    while (n != 1 && !set.contains(n)) {
      set.add(n);
      int sum = 0;
      while (n > 0) {
        int temp = n % 10;
        sum += temp * temp;
        n /= 10;
      }
      n = sum;
    }
    if (n != 1) {
      result = false;
    }
    return result;
  }
}

class Solution1 {
  public void reverseString(char[] s) {
    for (int i = 0; i < s.length / 2; i++) {
      char temp = s[i];
      s[i] = s[s.length - i - 1];
      s[s.length - i - 1] = temp;
    }
  }
}

class Solution {
  public boolean checkOnesSegment(String s) {
    for (int i = 1; i < s.length(); i++) {
      if (s.charAt(i) == '1' && s.charAt(i - 1) == '0') {
        return false;
      }
    }
    return true;
  }
}

public class one {
  public static void main(String[] args) {
    System.out.println("hello world");
    System.out.println(2.0 - 1.1);
  }
}
