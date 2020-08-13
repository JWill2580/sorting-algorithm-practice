package week12;


/**
 * Class implementing the quicksort method which can be seen through
 * the sortapp.
 * @author Josh Wilson
 */
public class QuickSort extends Sorter {

    /**
     * Quick Sort method that takes int array as parameters initializes
     * the array in the parent class.
     * @param nums the array to be sorted using quicksort
     */
    public QuickSort(Integer[] nums) {
        super(nums); 
    }

    /**
     * sortNums method that calls the support method quickSort which
     * sorts the array nums as a quicksort.
     */
    public void sortNums() {
        quickSort(0, nums.length - 1);
    }

    /**
     * Quick sort method that assignes the partition of the left and right
     * position to variable p and then sorts both sets.
     * @param left the left most position
     * @param right the right most position
     */
    public void quickSort(int left, int right){
        if (left < right){
            int p = partition(left, right);
            quickSort(left, p);
            quickSort(p + 1, right);
        }
        update();
    }

    /**
     * Partitioning the array taking left position and right position as
     * parameters.
     * @param left the left most position in the array
     * @param right the right most position in the array
     * @return hole the partition point
     */
    public int partition(int left, int right){
        int pivot = nums[left];
        int hole = left; i = left + 1; j = right;

        while (true){
            while (j > hole && nums[j] >= pivot){
                comparisons++;
                j--;
            }
            if (j == hole) {
                break;
            }
            nums[hole] = nums[j];
            hole = j;
            while (i < hole && nums[i] < pivot){
                i++;
                comparisons++;
                update();
            }
            if (i == hole) {
                break;
            }
            nums[hole] = nums[i];
            hole = i;
        }
        nums[hole] = pivot;
        update();
        return hole;
    }
}
