//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
//Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
//The solution set must not contain duplicate triplets.
//    For example, given array S = {-1 0 1 2 -1 -4},
//
//    A solution set is:
//    (-1, 0, 1)
//    (-1, -1, 2)
package leetcodeJava;

import java.util.ArrayList;
import java.util.List;

public class leetcode15 {

	public List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> res = new ArrayList<>(); 
		return null;   
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int nums[] = {-1,0,1,2,-1-4};
		List<List<Integer>> list = new leetcode15().threeSum(nums);
		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i).toString());;
		}
	}

}
