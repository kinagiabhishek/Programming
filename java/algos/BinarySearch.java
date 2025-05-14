package java.algos;

public class BinarySearch {
    public static int binarySearchIterative(int[] arr, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return binarySearchIterative(arr, target, mid + 1, right);
        } else {
            return binarySearchIterative(arr, target, left, mid - 1);
        }
    }

    public static int binarySearchIterative(int[] arr, int target) {
        int left = 0, right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid; // Element found
            } else if (arr[mid] < target) {
                left = mid + 1; // Search right half
            } else {
                right = mid - 1; // Search left half
            }
        }
        return -1; // Element not found
    }

    public static void main(String[] args) {
        int[] sortedArray = {2, 3, 4, 10, 40};
        int target = 10;

        int result_i = binarySearchIterative(sortedArray, target);
        System.out.println("Element found Iteratively at index: " + result_i);

        int result_r = binarySearchIterative(sortedArray, target, 0,sortedArray.length -1 );
        System.out.println("Element found Recursively at index: " + result_r);
    }
}