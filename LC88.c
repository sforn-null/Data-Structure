//方法一
//先合并再统一排序
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    int str1 = m;
//    int str2 = 0;
//    int a = 0;
//    while (str2 < n)
//    {
//        nums1[str1++] = nums2[str2++];
//    }
//    for (int i = 0;i < m + n - 1;i++)
//    {
//        for (int j = 0;j < m + n - i - 1;j++)
//        {
//            if (nums1[j] > nums1[j + 1])
//            {
//                a = nums1[j];
//                nums1[j] = nums1[j + 1];
//                nums1[j + 1] = a;
//            }
//        }
//    }
//}

//这里其实可以不用自己写冒泡排序，用qsort就行

//方法二 逆双指针
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//	int end1 = m - 1;
//	int end2 = n - 1;
//	int end = n + m - 1;
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if (nums1[end1] > nums2[end2])
//		{
//			nums1[end] = nums1[end1];
//			end--;
//			end1--;
//		}
//		else
//		{
//			nums1[end] = nums2[end2];
//			end--;
//			end2--;
//		}
//	}
//	while (end1 >= 0)
//	{
//		nums1[end--] = nums1[end1--];
//	}
//	while (end2 >= 0)
//	{
//		nums1[end--] = nums2[end2--];
//	}
//}
