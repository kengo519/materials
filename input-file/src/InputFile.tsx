import React, { useState } from 'react';
import './InputFile.css';

const isJSON = (name: string): boolean => {
  return "json" === name.split(".").at(-1);
}

export const App: React.FC = () => {
  const [name, setName] = useState<string>();

  return (
    <React.Fragment>
      <div className="input-file">
        <input id="input-file" type="file" accept='.json' onChange={(event: React.ChangeEvent<HTMLInputElement>) => {
          const files = event.currentTarget.files;
          // ファイルがなければ終了
          if (!files || files?.length === 0) return;
          // 先頭のファイルを取得
          const file = files[0];
          setName(file.name);
        }} />
      </div>
      <button onClick={(): void => {
        const element = document.getElementById("input-file");
        element?.click();
      }}>
        ボタン
      </button>
      <br />
      {name ? isJSON(name) ? "JSONファイルです。" : "JSONファイルではありません。" : null}
    </React.Fragment>
  );
}
