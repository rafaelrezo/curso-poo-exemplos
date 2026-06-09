import sqlite3


def mostrar_leituras() -> list[tuple]:
    # Contraexemplo: a função de tela conhece o banco e o SQL.
    # Isso dificulta testar a tela sem abrir um banco real.
    conexao = sqlite3.connect(":memory:")
    conexao.execute(
        """
        CREATE TABLE leituras (
            timestamp TEXT,
            tag TEXT,
            valor REAL,
            unidade TEXT,
            status TEXT
        )
        """
    )
    conexao.execute(
        """
        INSERT INTO leituras (timestamp, tag, valor, unidade, status)
        VALUES (?, ?, ?, ?, ?)
        """,
        ("2026-06-09T10:00:00-03:00", "LT-101", 42.0, "%", "operando"),
    )

    cursor = conexao.execute(
        "SELECT timestamp, tag, valor, unidade, status FROM leituras"
    )
    linhas = cursor.fetchall()
    conexao.close()
    return linhas


def main() -> None:
    for linha in mostrar_leituras():
        print(linha)


if __name__ == "__main__":
    main()
