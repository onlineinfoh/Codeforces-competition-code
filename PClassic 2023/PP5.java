import java.io.*;
import java.util.StringTokenizer;
public class PP5 {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());

		int len = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(r.readLine());

		int holder = 0;
		
		int[] arr = new int[len];

		for(int a = 0; a< len; a++){
			arr[a] = Integer.parseInt(st.nextToken());
		}

		int maxNum = arr[0];//

		int ans = 0;
		for(int b = 1; b< len; b++){
			maxNum = Math.max(maxNum, arr[b]);
			if(k ==0){break;}
			if(arr[b] >= arr[b-1]){
				ans+=arr[b];
				k--;
			}
			else{
				holder = Math.max(holder, ans+k*arr[b-1]);
				ans+=arr[b];
				k--;
			}
		}

		ans+=k*maxNum;

		pw.print(Math.max(ans, holder));
		
		pw.close();
	}
}