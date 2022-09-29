# A github repository for the Block-chain course

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

- To hash 100 000 rows, which each length varies from 2 to 1 000 symbols, it took **25.3471s**.<br> **Minimum, Average, Maximum** HEXADECIMAL similarities were:

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
