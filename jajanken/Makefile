# じゃじゃんけん (元ネタ ハンターハンター)

# Makefile for jajanken game
CFLAGS = -Wall -Wextra -Werror
TARGET = jajanken
SOURCE = main.c
HEADER = main.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE) $(HEADER)
	@echo "🔨 $(TARGET) をコンパイル中..."
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "✅ ビルド完了!"

# Run the game
run: $(TARGET)
	@./$(TARGET)

# Clean up build files
clean:
	@echo "🧹 クリーンアップ中..."
	rm -f $(TARGET) $(TARGET)_debug *.o
	@echo "✅ クリーンアップ完了!"

# Display help
help:
	@echo "🎯 じゃじゃんけん - 利用可能なコマンド:"
	@echo "  make        - ゲームをビルド"
	@echo "  make run    - ゲームをビルドして実行"
	@echo "  make clean  - ビルドファイルを削除"
	@echo "  make help   - このヘルプを表示"

# Phony targets declaration
.PHONY: all run clean help