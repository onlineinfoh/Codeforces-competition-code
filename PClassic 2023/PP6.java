import java.io.*;
import java.util.StringTokenizer;
public class PP6 {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());

		int num = Integer.parseInt(st.nextToken());

		int[] fac = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

		String[] covert = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C"};

		String ans = "";

		for(int a = fac.length-1; a>=0; a--){
			int div = fac[a];
			int toAdd = num/fac[a];
			num = num%fac[a];

			if(ans.equals("")){
				if(toAdd == 0){
					continue;
				}
				else{
					ans = covert[toAdd];
				}
			}
			else{
				ans += covert[toAdd];
			}
		}

		pw.print(ans);
		
		pw.close();
	}
}