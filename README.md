# A github repository for the Block-chain course

## Efficiency analysis

- Time taken to hash [konstitucija.txt](https://www.dropbox.com/s/ce83ry9a4d9642z/konstitucija.txt?dl=0) (789 rows) : 0.033748 s.

## Achieved things:

- If row is long and you change **a symbol / few symbols**, it rewards you with an avalanche effect <br> **(simply simply simply -> SIMPLY SIMPLY SIMPLY)**<br>

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

- If row is **short and you change a symbol**, it rewards you with an avalanche effect<br>

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

- **Single symbol / character** gives you this

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

## ~~Problems:~~

### SOLVED

- If row gets too long and the beggining words are the same, hash becomes the same with all other rows that have the same beggining<br>

    ### Input:
    
    ```console
    lietuvos respubklikos aaa
    lietuvos respubklikos ccc
    ```
    ### Output:
    ```
    467ac4485941e954bb344c5a54d016486ff4b0c36d61460e826e56e6b7607042
    467ac4485941e954bb344c5a54d016486ff4b0c36d61460e826e56e6b7607042
    ```

## To Do:

- ~~Create an **Input class.**~~
- ~~Implement reading from a file.~~
- ~~Function to convert **decimal** values into **Hexadecimal** values.~~
- ~~Convert each row's text symbol into **ASCII** value.~~
- ~~...~~
- ~~**Improve/upgrade** hash function.~~
