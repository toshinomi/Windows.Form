using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/// <summary>
/// 画像処理設定のロジック
/// </summary>
class ComImageProcessingType
{

    /// <summary>
    /// ID
    /// </summary>
    public int Id { set; get; }

    /// <summary>
    /// 名称
    /// </summary>
    public string Name { set; get; }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    public ComImageProcessingType()
    {
    }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="nId">ID</param>
    /// <param name="_strNmae">名称</param>
    public ComImageProcessingType(int nId, string strNmae)
    {
        Id = nId;
        Name = strNmae;
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ComImageProcessingType()
    {
    }

    /// <summary>
    /// クローン
    /// </summary>
    /// <returns>画像処理設定のクローン</returns>
    public object Clone()
    {
        return (ComImageProcessingType)MemberwiseClone();
    }
}