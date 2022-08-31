#include <SwitchControlLibrary.h>

//bool isUseFood = false; // ※将来的に対応予定

// コントローラ認識まで
void setup() {

  // 初期化
  SwitchControlLibrary();

  // A連打してコントローラーを認識させる
  for (int i = 0; i < 10; i++) {
    pushButton(Button::A);
    delay(100);
  }

  // マクロ開始までのディレイ
  delay(2000);

  // マクロ開始したかわかるための行動（ジャンプ）
  pushButton(Button::B);
  delay(2000);
}

// マクロ本体
void loop() {

  // メニュー開く (X)
  pushButton(Button::X);
  delay(3000);
  
  // ハットキー下下 (↓↓)
  pushHat(HatButton::DOWN);
  delay(500);
  pushHat(HatButton::DOWN);
  delay(500);
  
  // マップ開く (A)
  pushButton(Button::A);
  delay(1000);
  
  // 詳細エリア開く (A)
  pushButton(Button::A);
  delay(1000);
  
  // リスト検索 (+)
  pushButton(Button::PLUS);
  delay(500);
  
  // ハットキー下下 (↓↓)
  pushHat(HatButton::DOWN);
  delay(500);
  pushHat(HatButton::DOWN);
  delay(500);
  
  // 名を冠する者の墓を選択 (A)
  pushButton(Button::A);
  delay(500);
  
  // ハットキー下 (↓)
  pushHat(HatButton::DOWN);
  delay(500);
  
  // セラティニアを選択 (A)
  pushButton(Button::A);
  delay(500);
  
  // 移動を選択 (A)
  pushButton(Button::A);
  delay(500);

  // ～移動中～
  delay(5000);
  
  // 右にちょっと移動 (スティック右)
  SwitchControlLibrary().moveLeftStick(Stick::MAX, Stick::NEUTRAL);
  SwitchControlLibrary().sendReport();
  delay(500);
  SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::NEUTRAL);
  SwitchControlLibrary().sendReport();
  delay(500);
  
  // 墓を選択 (A)
  pushButton(Button::A);
  delay(1000);
  
  // 再戦 (A)
  pushButton(Button::A);
  delay(1000);

  // 敵をターゲット (A)
  pushButton(Button::A);
  delay(1000);
  
  // 戦闘開始 (A)
  pushButton(Button::A);
  delay(1000);
  
  // 下にしばらく移動 (スティック下)
  SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::MAX);
  SwitchControlLibrary().sendReport();
  delay(10000);
  SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::NEUTRAL);
  SwitchControlLibrary().sendReport();
  delay(500);

  // ～10分くらい放置～
  delaySeconds(60 * 10); // 10分
  //delaySeconds(60); // 1分でテスト → 動作OK
  // ※ここで運悪く全滅すると「再戦しますか？」の選択でてマクロ続行ができない
  // 長時間放置の安定性を考えるのならば2～3分で退散というほうが結果が出る可能性ある

  // 特別メニュー表示 (-長押し)
  holdButton(Button::MINUS, 1500);
  delay(500);
  
  // 十字キー下 (↓)
  pushHat(HatButton::DOWN);
  delay(500);
  
  // ギブアップ (A)
  pushButton(Button::A);
  delay(500);
  
  // 十字キー下 (↑)
  pushHat(HatButton::UP);
  delay(500);
  
  // はい (A)
  pushButton(Button::A);
  delay(500);
  
  // ～移動中～
  
  delay(5000);
  // 以後繰り返せるはず…
}
