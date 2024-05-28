import java.io.*;
import java.util.StringTokenizer;
public class P1 {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());

		int num = Integer.parseInt(st.nextToken());

		for(int a = 0; a< num; a++){
			st = new StringTokenizer(r.readLine());
			int one = Integer.parseInt(st.nextToken());
			int two = Integer.parseInt(st.nextToken());
			int three = Integer.parseInt(st.nextToken());

			if(one< two && two < three){
				pw.println("STAIR");
			}
			else if(one< two && two > three){
				pw.println("PEAK");
			}
			else{
				pw.println("NONE");
			}
		}

		pw.close();
	}
}
