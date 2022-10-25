# A github repository for the Block-chain course

## Simplified Block-Chain technology <i>v0.2.1</i>

## Hash function pseudo code

```c++
decToHex(string):
	for(it : string)
		sum = sum + (int)it
	for(it : string)
		dec_num = (int)it * sum^2 * string.size()^4
		hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'}
		while(dec_num > 0)
			r = dec_num % 16
			hexdec_num = hex[r] + hexdec_num
			dec_num = dec_num / 16
	return hexdec_num

hashRow(string):
	hashedRow = decToHex(string)
	while(true)
		if(hashedRow.length() < 64)
			hashedRow = decToHex(hashedRow)
		else
			hashedRow.resize(64)
			break

```

## Efficiency analysis

- Time taken to hash [konstitucija.txt](https://www.dropbox.com/s/ce83ry9a4d9642z/konstitucija.txt?dl=0) (789 rows) : 0.033748s.
- After hashing 25 000 rows, which length were 10, 100, 500, 1 000 random symbols, no hashed rows were the same, thus I can say that the hash function is resistant to collision.

- To hash 100 000 pairs of rows, which each length varies from 2 to 1 000 symbols, it took **25.3471s**.<br> **Minimum, Average, Maximum** HEXADECIMAL similarities were:

    ```console
    minimum similarity: 0%
    average similarity: 41.3263%
    maximum similarity: 71.875%
    ```
    **Minimum, Average, Maximum** BINARY similarities were:
    
    ```console
    minimum similarity: 39.8438%
    average similarity: 70.5024%
    maximum similarity: 89.0625%
    ```
    Thus hash is not the best (weak avalanche effect). 

## Test analysis:

- If row is long and you change **a symbol / few symbols**<br> **(simply simply simply -> SIMPLY SIMPLY SIMPLY)**<br>

    ### Input:
    
    ```console
  Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.Lorem Ipsum is simply simply simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.

  Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.Lorem Ipsum is SIMPLY SIMPLY SIMPLY dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
    ```
    
    ### Output:
    
    ```console
    7e95eab8decabddfaaa8368ab58b8a354d6a79940aba8b6abf884ac2dc8ab58b
    7de8eab7e48abcdf2aa755cab494ca35056a78f04ab98f6abe870ac1d7cab494
    ```

- If row is **short and you change a symbol**<br>

     ### Input:

     ```console
     hubertas
     Hubertas
     hubertas!
     ```

     ### Output:
     
     ```console
     1e2bc20a243e3041f668213fa1e2bc227b62318c3ecda1d8e61e2bc2004e2318
     3dbee22d8e219fe210361df4e219fe3be962066e1d5861df4e1f2de3d2263be9
     1faa122e5c3f54824d59414551faa124d5924d591f056409fa1faa12240522e5
     ```

- **Single symbol / character**

    ### Input:

    ```console
    a
    b
    ```
    
    ### Output:

    ```console
    a3f3a0b89a56ad9ca3f3a72a9a56ad9cad9ca3f39a56ad9ca3f3b0d79a56ad9c
    d9fef4261b3f6e2b6d9fe1ab3ee2b6de52d9fe1b3f61ab3e1b84ad9fef4261b3
    ```

## Conclusion
- After doing all the tests, I couldn't find any collisions;
- The complexity of the hash function is linear O(n);
```console
Time taken to hash 25 000 rows of length 10: 0.3635s.
Time taken to hash 50 000 rows of length 10: 0.753983.
```
- The average avalanche effect is ~41%.<br> (According to [geeksforgeeks](https://www.geeksforgeeks.org/avalanche-effect-in-cryptography/) a good hash function satisfies avalanche effect when the similarity is < 50%)

## My hash function comparison to [SHA-256](http://www.zedwood.com/article/cpp-sha256-function)

 ## Efficiency analysis
 
 - Here is a graphical representation of time taken to hash konstitucija.txt using **my hash** and **SHA-256** functions
 
 ![image](https://user-images.githubusercontent.com/93277255/193537617-96c4a2dd-fbb4-4f45-954a-0833f1bdb7dc.png)
 
|     |	 SHA-256  | "My hash" |
| --- | --------- | --------- |
|   2 |	0.0000112 | 0.0000429 |
|   4 |	0.0000192 | 0.0000683 |
|   8 |	0.0000337 | 0.000143  |
|  16 |	0.0000626 | 0.0003718 |
|  32 |	0.0001165 | 0.0007935 |
|  64 |	0.0002254 | 0.0016706 |
| 128 |	0.0004453 | 0.0045257 |
| 256 |	0.0008947 | 0.0107233 |
| 512 |	0.0019355 | 0.0233524 |
| 789 |	0.0029294 | 0.035413  |
 
 - Here is a graphical representation of **SHA-256** AND **My hash** functions similarities, when hashing 100 000 pairs of rows, which each length varies from 2 to 1 000 symbols
 
 ![image](https://user-images.githubusercontent.com/93277255/193538884-9db2e0bb-c938-45c1-9277-9077af081cb0.png)
 
|           | SHA-256 |  "My hash" |
| --------- | ------- | ---------- |	    
|  Hex, min |  0.00%  |	   0.00%   |
|  Hex, avg |  6.27%  |	  41.33%   |
|  Hex, max | 23.44%  |	  71.88%   |
| Bits, min | 36.33%  |	  39.84%   |
| Bits, avg | 50.03%  |	  70.50%   |
| Bits, max | 62.50%  |   89.06%   |

## Hashing with salt analysis

- Salt is a randomly generated string of characters of size 14.
- Each input has a different salt value.

   ### Input:
   
    ```console
    hubertas
    hubertas
    ```
    
    ### Output:
    
    ```console
    4231e4a77d3e5f84048d488e849d4a3dbc94931b1f2f91e8d621bbd1f2f91e8d
    3db36456903a23a3beb043a1a44d1e398b84439c20a141d1181ed9e20a1421d0
    ```
    
- Similarity between these 2 hashes+salt is **14.0625%**

## Conclusion

 - The same input hashed with different salt values outputs different hash.
