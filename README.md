# A github repository for the Block-chain course

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
     1e44220bca3e62a1f8061da601e44222970233523f00c215ac1e442201e82335
     3df1022f5021bb01d7001e0d021bb03c1a020810211e01e0d01f4703d5403c1a
     2147e24ad4428fc26b6e260902147e26b6e26b6e209a0428fc2147e23ff624ad
     ```

- **Single symbol / character** gives you this

    ### Input:

    ```console
    a
    b
    ```
    
    ### Output:

    ```console
    e64cd8c01c390ead0e64ce1c81bf0cfce0f3d8d8c01b6041c814e1c81cc981c3
    e2f4102bae77ef51ce2f41bcd41b84a1cefce2f41ca72e2f4fe30e2f41b84a1c
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
- ...
- **Improve/upgrade** hash function.
