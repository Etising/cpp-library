# template
どのコードにも基本includeしています

ざっくりとした説明

## 定数倍高速化(1-6)
`#pragma GCC target("avx2")`はAtCoderで使えないのでコメントアウト  
`#pragma GCC optimize("Ofast")`は場合によっては遅くなるので基本コメントアウト  
`#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")`は自分の環境だとうまく動かないので封印しています  
- 定数倍高速化が役に立ったことがまだないので、実はあまり意味なかったり  

## local debug(11-17)
stdにあるコンテナであれば`debug(...);`と書くだけでいい感じに出力してくれるやつです  
手元実行の際に"LOCAL"ラベルを付けてコンパイルすることで提出の際にいちいち消す必要がありません  

※ぼくのではありません、詳しくは[こちら](https://blog.naskya.net/post/0002/)

## 実行時間計測(149-159)
### コンストラクタ
```cpp
exec_time et
```
実行時間を計測するクラスexec_timeを作ります。
同時に、実行時間の計測を開始します。

### get_time
```cpp
long long get_time()
```
コンストラクタを実行～get_time()を実行までの時間をms表記で返します。