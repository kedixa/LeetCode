class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l1=len(nums1)
        l2=len(nums2)
        L=l1+l2
        a=nums1
        b=nums2
        i=0
        j=0
        tmp=0
        tmp1=0
        tmp2=0
        if L%2:
            while (i+j)<L/2:
                if (i<l1)&(j<l2):
                    tmp=min(a[i],b[j])
                    if (i+1<l1)&(j+1<l2):
                        if (a[i+1]<b[j+1]):
                            i+=1
                        else:
                            j+=1
                    elif i+1==l1:
                        if (a[i]==tmp):
                            i+=1
                        else:
                            j+=1
                    elif j+1==l2:
                        if (b[j]==tmp):
                            j+=1
                        else:
                            i+=1
                elif i==l1:
                    tmp=b[j]
                    j+=1
                elif j==l2:
                    tmp=a[i]
                    i+=1
            return tmp
        else:
            tmp=min(a[0],b[0])
            if tmp==a[0]:
                i+=1
            else:
                j+=1
            while True:
                if (i+j)>L/2:
                    break
                if (i<l1)&(j<l2):
                    tmp1=min(a[i],b[j])
                    if (i+1<l1)&(j+1<l2):
                        if (a[i+1]<b[j+1]):
                            i+=1
                        else:
                            j+=1
                    elif i+1==l1:
                        if (a[i]==tmp1):
                            i+=1
                        else:
                            j+=1
                    elif j+1==l2:
                        if (b[j]==tmp1):
                            j+=1
                        else:
                            i+=1
                elif i==l1:
                    tmp1=b[j]
                    j+=1
                elif j==l2:
                    tmp1=a[i]
                    i+=1
                if (i<l1)&(j<l2):
                    tmp2=min(a[i],b[j])
                    if (i+1<l1)&(j+1<l2):
                        if (a[i+1]<b[j+1]):
                            i+=1
                        else:
                            j+=1
                    elif i+1==l1:
                        if (a[i]==tmp2):
                            i+=1
                        else:
                            j+=1
                    elif j+1==l2:
                        if (b[j]==tmp2):
                            j+=1
                        else:
                            i+=1
                elif i==l1:
                    tmp2=b[j]
                    j+=1
                elif j==l2:
                    tmp2=a[i]
                    i+=1
            return (tmp1+tmp2)/2

            
a=Solution()
b=a.findMedianSortedArrays([1,3],[2])
print(b)
b=a.findMedianSortedArrays([1],[2,3])
print(b)
b=a.findMedianSortedArrays([3],[1,2])
print(b)