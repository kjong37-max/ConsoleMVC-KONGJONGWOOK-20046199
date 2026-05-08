# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 프로젝트 개요

이 프로젝트는 **MVC 스켈레톤 코드에 대한 PoC(Proof of Concept) 개발**을 목적으로 한다. C++20 기반의 Windows 콘솔 애플리케이션으로, MVC(Model-View-Controller) 아키텍처 패턴의 구현을 탐구한다.

## 기술 스택

- **언어**: C++20 (`stdcpp20`)
- **빌드 시스템**: MSBuild (Visual Studio 2022, v145 툴셋)
- **플랫폼**: Windows (Win32 / x64)
- **출력 형식**: 콘솔 애플리케이션
- **문자셋**: Unicode

## 빌드 명령

### Visual Studio GUI
- `F5` — 빌드 후 실행 (디버그)
- `Ctrl+Shift+B` — 솔루션 빌드

### 커맨드라인 (MSBuild)
```powershell
# Debug x64
msbuild Project1.vcxproj /p:Configuration=Debug /p:Platform=x64

# Release x64
msbuild Project1.vcxproj /p:Configuration=Release /p:Platform=x64
```

솔루션 파일 기준으로 빌드할 경우:
```powershell
msbuild ..\MVC_skelton.slnx /p:Configuration=Debug /p:Platform=x64
```

## 프로젝트 구조 및 MVC 아키텍처

현재는 스켈레톤 상태이며, 아래 구조로 MVC 레이어를 구성한다.

```
Project1/
├── Model/          # 데이터 및 비즈니스 로직 (도메인 엔티티, 데이터 접근)
├── View/           # 출력·UI 레이어 (콘솔 렌더링, 화면 표시)
├── Controller/     # 입력 처리 및 Model-View 중재
└── main.cpp        # 진입점, MVC 인스턴스 생성 및 실행 루프
```

Visual Studio 필터(`Project1.vcxproj.filters`)도 같은 구조로 유지한다.

## 개발 규칙

- 소스 파일(`.cpp`)과 헤더 파일(`.h`/`.hpp`)을 각 MVC 레이어 디렉터리에 위치시킨다.
- 새 파일 추가 시 `.vcxproj`의 `<ItemGroup>` 및 `.vcxproj.filters`에 항목을 등록해야 빌드에 포함된다.
- SDL 보안 검사와 경고 수준 3(`/W3`)이 기본 활성화되어 있다.
- C++20 기능(모듈, 컨셉, 범위 등)을 활용할 수 있다.
