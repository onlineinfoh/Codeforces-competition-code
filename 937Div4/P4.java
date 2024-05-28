import java.io.*;
import java.util.StringTokenizer;
public class P4 {
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
		boolean is = true;
		for(int a = 0; a< s.length(); a++){
			if(! ((s.charAt(a)+"").equals("0") || (s.charAt(a)+"").equals("1"))){
				is = false;
			}
		}
		if(is){
			return "YES";
		}

		int num = Integer.parseInt(s);
		int n = 0;
		while(n <4){
			if(num%10 == 0){
				num/= 10;
			}
			else if(num%11 ==0){
				num/=11;
			}
			else if(num%101 ==0){
				num/=101;
			}
			else if(num%111 ==0){
				num/=111;
			}
			else if(num%1101 ==0){
				num/=1101;
			}
			else if(num%1011 ==0){
				num/=1011;
			}
			else if(num%1001 ==0){
				num/=1001;
			}
			n++;
		}
		if(num == 1){
			return "YES";
		}
		return "NO";
	}
}