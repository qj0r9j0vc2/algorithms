# algorithms
 example algorithm implements.
 - Huffman
   - **algorithm that compress data, and it forms basic compress concept.**
     - It starts with a priority queue as elements a binary tree with letters and counts. 
     - In first, it takes two elements from priority queue. and create new binary tree under the root node that has child node that result from the above process. then repeat the above operation.
     - Repeat the above operation until there is only one element in the queue, resulting in one binary tree that representing Huffman code.
     - Put '0' in the result for each left seek, and '1' for each right seek.  

