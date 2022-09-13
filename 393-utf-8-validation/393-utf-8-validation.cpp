class Solution{
public:
  bool validUtf8(vector<int> &data){
    int n = data.size(); 
    int count = 0;       
    for (int i = 0; i < n; i++){    
      int element = data[i]; 
      if (!count){ 
	   // if the first 3 bits are 110, then the next byte is part of the current UTF-8 character
        if ((element >> 5) == 0b110) 
          count = 1; 
		// if the first 4 bits are 1110, then the next 2 bytes are part of the current UTF-8 character  
        else if ((element >> 4) == 0b1110)
          count = 2; 
		 // if the first 5 bits are 11110, then the next 3 bytes are part of the current UTF-8 character
        else if ((element >> 3) == 0b11110)
          count = 3; 
		 // if the first bit is 1, then return false
        else if ((element >> 7))
          return false; 
      }
      else{
	   // if the first 2 bits are not 10, then return false
        if ((element >> 6) != 0b10)
          return false; 
        count--;        
      }
    }
    return (count == 0); 
  }
};