import java.io.*;
import java.util.StringTokenizer;
public class P3 {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());

		int num = Integer.parseInt(st.nextToken());

		for(int a = 0; a< num; a++){
			st = new StringTokenizer(r.readLine());
			String input = st.nextToken();
			pw.println(Ans(input));
		}
		pw.close();
	}
	public static String Ans(String s){
		if(s.equals("12:00")){
			return "12:00 PM";
		}
		if(s.equals("00:00")){
			return "12:00 AM";
		}
		String half = "";
		String h = s.substring(0, 2);
		String m = s.substring(3);
		if(Integer.parseInt(h)<12){
			half = " AM";
			if(Integer.parseInt(h) == 0){
				h = "12";
			}
			h = Integer.parseInt(h)+"";
		}
		else{
			half = " PM"; 
			if(!(Integer.parseInt(h)==12)){
				int holder = Integer.parseInt(h)-12;
				h = holder+"";
			}
		}
		if(Integer.parseInt(h)<=9){
			return "0"+h+":"+m+half;
		}
		return h+":"+m+half;
	}
}
