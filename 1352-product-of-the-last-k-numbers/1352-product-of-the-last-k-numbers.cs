public class ProductOfNumbers
{
    private List<int> numbers;
    public ProductOfNumbers()
    {
        numbers = new List<int>();
    }

    public void Add(int num)
    {
        numbers.Add(num);
    }

    public int GetProduct(int k)
    {
        int res = 1;
        for (int i = numbers.Count - 1 , j = 0; j < k; i-- , j++) 
            res *= numbers[i];
        return res;
    }
}