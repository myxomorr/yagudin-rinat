# Папка для сборки
BUILD_DIR := build

# Исполнимые файлы
SERVER_EXEC := server
CLIENT_EXEC := client

# Путь к CMake
CMAKE := cmake
MAKE := make

# Создание директории build, если она не существует
$(BUILD_DIR):
	@echo "Создание директории $(BUILD_DIR)"
	mkdir -p $(BUILD_DIR)

# Запуск CMake и сборка всего проекта
build: $(BUILD_DIR)/Makefile
	@echo "Сборка проекта..."
	cd $(BUILD_DIR) && $(CMAKE) ..
	cd $(BUILD_DIR) && $(MAKE)

# Запуск сервера
run_server: build
	@echo "Запуск сервера..."
	./$(BUILD_DIR)/$(SERVER_EXEC)

# Запуск клиента
run_client: build
	@echo "Запуск клиента..."
	./$(BUILD_DIR)/$(CLIENT_EXEC)

# Очистка всех сгенерированных файлов и папок
clean:
	@echo "Очистка..."
	rm -rf $(BUILD_DIR)

.PHONY: build run_server run_client clean
