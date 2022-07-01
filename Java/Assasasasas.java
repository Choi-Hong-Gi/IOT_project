import java.util.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Assasasasas {
	
	public static int countChar(String str, char ch) {
		int count = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == ch) {
				count++;
				}
			}
		return count;
		}

	public static void main(String[] args) {
		
		List<String> aaa1 = new ArrayList<String>();
		List<String> aaa2 = new ArrayList<String>();
		List<String> aaa3 = new ArrayList<String>();
		
		String a = "<font size=\"7\" color=\"white\"> == $0\n"
				+ "  \"38.9\"\n  <br>\n <\\font> 수온: @34.1<br>\\n"
				+ "<\\\\font> 날짜: @06-12<br>\\n <\\\\font> 시간: @15:45<br>\\n <\\\\font> "
				+ "<font size=\"7\" color=\"white\"> == $0\n"
				+ "  \"38.9\"\n  <br>\n <\\font> 수온: @34.1<br>\\n"
				+ "<\\\\font> 날짜: @06-13<br>\\n <\\\\font> 시간: @15:45<br>\\n <\\\\font> "
				+ "<font size=\"7\" color=\"white\"> == $0\n"
				+ "  \"38.9\"\n  <br>\n <\\font> 수온: @34.1<br>\\n"
				+ "<\\\\font> 날짜: @06-14<br>\\n <\\\\font> 시간: @15:45<br>\\n <\\\\font> "
				+ "<font size=\"7\" color=\"white\"> == $0\n"
				+ "  \"38.9\"\n  <br>\n <\\font> 수온: @34.1<br>\\n"
				+ "<\\\\font> 날짜: @06-15<br>\\n <\\\\font> 시간: @15:45<br>\\n <\\\\font> ";
		
		System.out.println(a);
		
		int x = countChar(a, '@');
		
		for(int z = 0; z < x/3; z++) {
			int aa = a.indexOf("수온: @");
			int bb = a.indexOf("날짜: @");
			int cc = a.indexOf("시간: @");
			
			String vv1 = a.substring(aa+5, aa+7);
			String vv2 = a.substring(bb+5, bb+10);
			String vv3 = a.substring(cc+5, cc+10);
			
			aaa1.add(vv1);
			aaa2.add(vv2);
			aaa3.add(vv3);
			
			a = a.substring(cc+10);
		}
		
		
		
		System.out.println(aaa1);
		System.out.println(aaa2);
		System.out.println(aaa3);
		
		System.out.println(aaa3.size());
		
		while(aaa3.size() != 1)
		{
			aaa3.remove(0);
		}
		
		System.out.println(aaa3.size());

	}

}
