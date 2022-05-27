public class Solution 
{
    public class TrieNode
    {
        public TrieNode[] Children = new TrieNode[2];
    }
    
    public int FindMaximumXOR(int[] nums) 
    {
        TrieNode root = new TrieNode();
                
        foreach(var num in nums)
        {
            TrieNode node = root;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (num & (1 << i)) != 0 ? 1 : 0;              
                if(node.Children[bit] == null)
                {
                    node.Children[bit] = new TrieNode();
                }
                    
                node = node.Children[bit];                    
            }
        }
        
        int result = int.MinValue;
        
        foreach(var num in nums)
        {
            TrieNode node = root;
            int xorValue = 0;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (num & (1 << i)) != 0 ? 1 : 0;
                int flipBit = bit == 0 ? 1 : 0;
                
                if(node.Children[flipBit] != null)
                {
                    xorValue |= (1 << i);                    
                    node = node.Children[flipBit];
                }
                else
                {
                    node = node.Children[bit];                        
                }
            }
            
            result = Math.Max(result, xorValue);
        }
                
        return result;        
    }
}