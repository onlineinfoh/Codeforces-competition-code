import java.io.*;
import java.util.StringTokenizer;
public class P2 {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());

		int num = Integer.parseInt(st.nextToken());

		for(int a = 0; a< num; a++){
			st = new StringTokenizer(r.readLine());
			int scale = Integer.parseInt(st.nextToken());
			int counter = 0;
			for(int i = 0; i< scale; i++){
				String holder = "";
				for(int j = 0; j< scale; j++){
					if(counter%2 == 0){
						holder+="##";
						counter++;
					}
					else{
						holder+="..";
						counter++;
					}
				}
				pw.println(holder+"\n"+holder);
				if(scale%2 == 0){
					counter -= 1;
				}
			}
		}

		pw.close();
	}
}
