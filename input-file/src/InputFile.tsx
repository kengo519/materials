import React, { ChangeEventHandler } from 'react';
import './InputFile.css';

const useInputFile = () => {
  const handleFiles: ChangeEventHandler<HTMLInputElement> = (event) => {
    const files = event.currentTarget.files;
    if (!files || files?.length === 0) return;
    const file = files[0];
    console.log('file:', file);
  };
  return { handleFiles };
}

const onChange = (event: React.ChangeEvent<HTMLInputElement>) => {
  const files = event.currentTarget.files;
  // ファイルがなければ終了
  if (!files || files?.length === 0) return;
  // 先頭のファイルを取得
  const file = files[0];
  console.log('file:', file);
}

export const App: React.FC = () => {
  const { handleFiles } = useInputFile();
  const onChangeHandle = (event: React.ChangeEvent<HTMLInputElement>) => {
    // event.currentTarget.files
  }

  return (
    <input type="file" accept='.json'/>
  );
}
