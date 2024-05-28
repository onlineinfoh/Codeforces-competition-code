// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.StringTokenizer;
import java.util.*;

public class Rumor {

	public static boolean[] checked = new boolean[1000000];

	public static List<Integer>[] pairs = new ArrayList[1000000];

	public static int[] amt = new int[1000000];

	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(r.readLine());
		int len = Integer.parseInt(st.nextToken());
		int pair = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(r.readLine());
		for(int a = 0; a< len; a++){
			amt[a] = Integer.parseInt(st.nextToken());
		}

		for(int c = 0; c< 1000000; c++){
			pairs[c] = new ArrayList<>();
			checked[c] = false;
		}

		for(int b = 0; b< pair; b++){
			st = new StringTokenizer(r.readLine());
			int one = Integer.parseInt(st.nextToken())-1;
			int two = Integer.parseInt(st.nextToken())-1;
			pairs[one].add(two);
			pairs[two].add(one);
		}

		long ans = 0;
		for(int x = 0; x< len; x++){
			if(!checked[x]){
				ans += dfs(x);
			}
		}

		pw.print(ans);
		
		pw.close();
	}

	public static int dfs(int x){
		int min = amt[x];
		checked[x] = true;

		for(int i: pairs[x]){
			if(! checked[i]){
				min = Math.min(min, dfs(i));
			}
		}

		return min;
	}
}
