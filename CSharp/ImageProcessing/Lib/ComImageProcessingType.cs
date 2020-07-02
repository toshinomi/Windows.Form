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
    /// <param name="Id">ID</param>
    /// <param name="Nmae">名称</param>
    public ComImageProcessingType(int Id, string Nmae)
    {
        this.Id = Id;
        this.Name = Nmae;
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