# template
どのコードにも基本includeしています

ざっくりとした説明

## 定数倍高速化(1-6)
`#pragma GCC target("avx2")`はAtCoderで使えないのでコメントアウト  
`#pragma GCC optimize("Ofast")`は場合によっては遅くなるので基本コメントアウト  
`#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")`は自分の環境だとうまく動かないので封印しています  
- 定数倍高速化が役に立ったことがまだないので、実はあまり意味なかったり  
