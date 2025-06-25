
# QtDictTranslator

基于 Qt/C++ 开发的跨平台电子词典/翻译工具，支持本地词库查询、在线有道翻译、历史记录、收藏夹和TTS语音朗读等功能。

---

## 功能特性

- **本地词库查询**：内置常用英汉词库，支持离线查询。
- **在线翻译**：集成有道翻译API，支持中英文互译。
- **历史记录**：自动保存查询历史，便于回顾和复习。
- **收藏夹**：支持单词收藏，方便重点单词管理。
- **TTS语音朗读**：支持中英文发音，提升学习体验。
- **数据持久化**：历史和收藏数据采用SQLite数据库本地存储。
- **跨平台支持**：可在Windows、Linux等主流桌面系统运行。

---

## 界面

![image](https://github.com/user-attachments/assets/45322269-8983-4f6f-b139-00f75d7ecfda)


---

## 快速开始

### 1. 克隆项目

### 2. 安装依赖

- 需要安装 Qt 5.12+（建议使用 Qt Creator）
- 需要安装 Qt Speech（texttospeech）、Qt SQL（sqlite）模块

### 3. 配置有道翻译API

- 注册并登录 [有道智云开放平台](https://ai.youdao.com/)
- 创建应用，获取 `appKey` 和 `appSecret`
- 在 `apimanager.cpp` 中填写你的 `appKey` 和 `appSecret`

```cpp
appKey = "你的appKey";
appSecret = "你的appSecret";
```

### 4. 编译运行

- 用 Qt Creator 打开项目，选择合适的 Kit，编译并运行即可。

---

## 文件结构

```
.
├── main.cpp
├── mainwindow.h/cpp/ui
├── dictmanager.h/cpp
├── apimanager.h/cpp
├── historymanager.h/cpp
├── favoritesmanager.h/cpp
├── ttsmanager.h/cpp
├── resources/
│   └── dict.csv
├── database.db
├── resources.qrc
└── README.md
```

---

## 打包发布

1. Release模式编译项目
2. 使用`windeployqt`（Windows）或`linuxdeployqt`（Linux）收集依赖
3. 将`resources/`和`database.db`一同打包分发

---

## 主要技术栈

- Qt Widgets
- Qt Network
- Qt SQL (SQLite)
- Qt TextToSpeech
- C++
- 有道翻译API
