# A github repository for the Block-chain course

## To Do:

- ~~Create an **Input class.**~~
- ~~Implement reading from a file.~~
- ~~Function to convert **decimal** values into **Hexadecimal** values.~~
- ~~Convert each row's text symbol into **ASCII** value.~~
- ...
- **Improve/upgrade** hash function.

## Problems:

- if row gets too long and the beggining words are the same, hash becomes the same with all other rows that have the same beggining<br>

### input:

1. lietuvos respubklikos aaa<br>
2. lietuvos respubklikos ccc<br>

### result:

1. 467ac4485941e954bb344c5a54d016486ff4b0c36d61460e826e56e6b7607042
2. 467ac4485941e954bb344c5a54d016486ff4b0c36d61460e826e56e6b7607042

## Achieved things:

- if row is short and you change a symbol it rewards you with an avalanche effect<br>

### input:

1. hubertas<br>
2. Hubertas<br>
3. hubertas!<br>

### result:

1. 1e44220bca3e62a1f8061da601e44222970233523f00c215ac1e442201e82335<br>
2. 3df1022f5021bb01d7001e0d021bb03c1a020810211e01e0d01f4703d5403c1a<br>
3. 2147e24ad4428fc26b6e260902147e26b6e26b6e209a0428fc2147e23ff624ad<br>
