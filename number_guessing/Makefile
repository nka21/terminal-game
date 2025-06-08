# 数字予想ゲーム
# 作者: naoki

# コンパイラと設定
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = number_guessing
SOURCE = main.c
HEADER = main.h

# デフォルトターゲット
all: $(TARGET)

# 実行ファイルをビルド
$(TARGET): $(SOURCE) $(HEADER)
	@echo "🔨 $(TARGET) をコンパイル中..."
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "✅ ビルド完了！"

# ゲームを実行
run: $(TARGET)
	@./$(TARGET)

# ビルドファイルを削除
clean:
	@echo "🧹 クリーンアップ中..."
	rm -f $(TARGET) $(TARGET)_debug *.o
	@echo "✅ クリーンアップ完了！"

# ヘルプ表示
help:
	@echo "🎯 数字予想ゲーム - 利用可能なコマンド:"
	@echo "  make        - ゲームをビルド"
	@echo "  make run    - ゲームをビルドして実行"
	@echo "  make clean  - ビルドファイルを削除"
	@echo "  make help   - このヘルプを表示"

# phonyターゲット宣言
.PHONY: all run clean help