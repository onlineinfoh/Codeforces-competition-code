import java.io.*;
import java.util.StringTokenizer;

public class sumofthesumofthedigits {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());

		int[] arr = new int[200001];

		for(int a = 0; a<= 200000; a++){
			String i = a+"";
			if(i.length() <2){
				arr[a] = a;
			}
			else{
				int sum = 0;
				for(int b = 0; b< i.length(); b++){
					sum+= Integer.parseInt(i.charAt(b)+"");
				}
				arr[a] = sum;
			}
			
		}

		for(int c = 1; c<= 200000; c++){
			arr[c] = arr[c] + arr[c-1];
		}

		int casen = Integer.parseInt(st.nextToken());

		for(int d = 0; d< casen; d++){
			st = new StringTokenizer(r.readLine());
			int num = Integer.parseInt(st.nextToken());
			pw.println(arr[num]);
		}

		pw.close();
	}
}
